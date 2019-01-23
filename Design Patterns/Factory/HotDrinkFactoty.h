#pragma once

#include "../../common.h"

#include "HotDrink.h"

namespace Factory
{
    struct HotDrinkFactory {
        virtual unique_ptr<HotDrink> make() const = 0;
    };

    struct TeaFactory : HotDrinkFactory
    {
        unique_ptr<HotDrink> make() const override {
            return make_unique<Tea>();
        }
    };

    struct CoffeeFactory: HotDrinkFactory
    {
        unique_ptr<HotDrink> make() const override {
            return make_unique<Coffee>();
        }
    };
}