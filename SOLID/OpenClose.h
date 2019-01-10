#pragma once

#include "../common.h"

enum class Color {red, green, blue};
enum class Size {small, medium, large};

struct Product
{
    string name;
    Color color;
    Size size;
};

struct ProductFilter
{
    vector<Product*> by_color(const vector<Product*> &items, Color color)
    {
        vector<Product*> result;
        for (auto &i : items)
            if (i->color == color)
                result.push_back(i);

        return result;
    }
};


template <typename T>
struct Specification
{
    virtual bool is_satisfied(T* item) = 0;
};

template <typename T>
struct AndSpecification : Specification<T>
{
    Specification<T> &first;
    Specification<T> &second;

    AndSpecification(Specification<T> &first, Specification<T> &second)
            : first(first), second(second) {}

    bool is_satisfied(T *item) override {
        return first.is_satisfied(item) && second.is_satisfied(item);
    }
};


struct SpecificationProduct : Specification<Product>
{
    AndSpecification<Product> operator&&(SpecificationProduct  &spec)
    {
        return AndSpecification<Product>(*this, spec);
    }
};

struct ColorSpecification : SpecificationProduct
{
    Color color;

    ColorSpecification(Color color): color(color) {}
    bool is_satisfied(Product* item) override
    {
        return item->color == color;
    }
};

struct SizeSpecification : SpecificationProduct
{
    Size size;

    SizeSpecification(Size size): size(size) {}
    bool is_satisfied(Product* item) override
    {
        return item->size == size;
    }
};

template <typename T>
struct Filter
{
    virtual vector<T*> filter(vector<T*> items, Specification<T> &spec) = 0;
};

struct BetterFilter : Filter<Product>
{
    vector<Product *> filter(vector<Product *> items, Specification<Product> &spec) override
    {
        vector<Product*> result;
        for (auto &i : items)
        {
            if (spec.is_satisfied(i))
                result.push_back(i);
        }
        return result;
    }
};


void testOpenClose()
{
    Product apple{ "Apple", Color::green, Size::small };
    Product tree{ "Tree", Color::green, Size::medium };
    Product house{ "House", Color::blue, Size::large };

    vector<Product*> products{&apple, &tree, &house};

    BetterFilter betterFilter;
    ColorSpecification specificationGreen(Color::green);
    SizeSpecification sizeSpecification(Size::medium);

    auto cpec = specificationGreen && sizeSpecification;
    for (auto &i : betterFilter.filter(products, cpec)){
        cout << "Green product: " << i->name << endl;
    }
}


