#include "PersonAddressBuilder.h"
#include "PersonJobBuilder.h"
#include "PersonBuilder.h"

PersonBuilderBase::PersonBuilderBase(Person &person) : person(person) {}

PersonAddressBuilder PersonBuilderBase::lives() const {
    return PersonAddressBuilder{person};
}

PersonJobBuilder PersonBuilderBase::works() const {
    return PersonJobBuilder{person};
}

PersonBuilder::PersonBuilder() : PersonBuilderBase(p) {}
