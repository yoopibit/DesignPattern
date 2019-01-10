#include "builderFacets.h"
#include "PersonBuilder.h"

PersonBuilder Person::create() {

    return PersonBuilder();
}

ostream &operator<<(ostream &os, const Person &person) {
    os << endl << "Person: Address = {" << person.city << ", " << person.street_address
       << ", " << person.post_code << "}\n" << "Employe = {" << person.position
       << ", " << person.company_name << ", " << person.annual_income << "}\n";

    return os;
}
