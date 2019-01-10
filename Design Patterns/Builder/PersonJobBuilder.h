#pragma once

#include "PersonBuilder.h"

class PersonJobBuilder : public PersonBuilderBase
{
    using Self = PersonJobBuilder;
public:
    explicit PersonJobBuilder(Person &person) : PersonBuilderBase(person) {

    }

    Self& at(string company_name)
    {
        person.company_name = company_name;
        return *this;
    }

    Self& as_a(string position)
    {
        person.position = position;
        return *this;
    }

    Self& earing(int annual_income)
    {
        person.annual_income = annual_income;
        return *this;
    }
};