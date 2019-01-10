#pragma once

#include "builderFacets.h"

class PersonJobBuilder;
class PersonAddressBuilder;

class PersonBuilderBase
{
protected:
    Person &person;
public:
    PersonBuilderBase(Person &person);

    operator Person() const {
        return move(person);
    }

    PersonAddressBuilder lives() const;
    PersonJobBuilder works() const;
};

class PersonBuilder : public PersonBuilderBase
{
private:
Person p;

public:
    PersonBuilder();
};
