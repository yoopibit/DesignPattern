#pragma once

#include "../../common.h"

class PersonBuilder;

class Person
{
    // address
    string street_address;
    string post_code;
    string city;

    // employment
    string company_name;
    string position;

    int annual_income{0};

    friend class PersonBuilder;
    friend class PersonJobBuilder;
    friend class PersonAddressBuilder;

public:
    static PersonBuilder create();

    friend ostream&operator << (ostream& os, const Person &person);
};
