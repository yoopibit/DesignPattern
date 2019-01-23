#pragma once

#include "Factory.h"
#include "HotDrinkFactoty.h"
#include "DrinkFactory.h"

unique_ptr<Factory::HotDrink> make_drink(const string &type)
{
    unique_ptr<Factory::HotDrink> drink;

    if (type == "tea")
    {
        drink = make_unique<Factory::Tea>();
        drink->prepare(200);
    } else {
        drink = make_unique<Factory::Coffee>();
        drink->prepare(50);
    }
    return drink;

}

void testFactory()
{
    Factory::DrinkFactory df;
    auto c = df.make_drink("coffee");
//
//    auto d = make_drink("tea");
//
//    auto p = Factory::Point::Factory.NewPolar(5, M_PI_4);
//
//    cout << p << endl;
}
