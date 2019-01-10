#pragma once

#include "../common.h"

class Rectangle
{
protected:
    int width;
    int height;

public:
    Rectangle(int width, int height) : width(width), height(height) {}

    int getWidth() const {
        return width;
    }

    virtual void setWidth(int width) {
        Rectangle::width = width;
    }

    virtual void setHeight(int height) {
        Rectangle::height = height;
    }

    virtual int getHeight() const {
        return height;
    }

    int area() const
    {
        return width * height;
    }
};

class Square : public Rectangle
{
public:
    Square(int size): Rectangle(size, size) {}

    void setWidth(int width) override {
        this->width = this->height = width;
    }

    void setHeight(int height) override {
        this->width = this->height = height;
    }
};

void process(Rectangle &r)
{
    int w = r.getWidth();
    r.setHeight(10);

    cout << "expected area = " << (w * 10) << ", got " << r.area() << endl;
}

struct RectangleFactory
{
    static Rectangle create_rectangle(int w, int height);
    static Rectangle create_square(int size);
};

void testLiskow()
{
    Rectangle r{3, 4};
    process(r);

    Square sq{5};
    process(sq);
}