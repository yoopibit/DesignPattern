#pragma once
#include "builderFacets.h"

#include "PersonBuilder.h"
#include "PersonAddressBuilder.h"
#include "PersonJobBuilder.h"

void testBuilderFacets()
{
    Person p = Person::create()
            .lives()
                    .at("123 London Road")
                    .with_postcode("SW1 1Gb")
                    .in("London")
            .works()
                    .at("PragmaSoft")
                    .as_a("Consultant")
                    .earing(1);

    cout << p;
}