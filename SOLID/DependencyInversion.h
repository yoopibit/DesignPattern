#pragma once

#include "../common.h"

enum class Relationship
{
    parent,
    child,
    sibling
};

struct Person1
{
    string name ;
};

struct RelationshipBrowser
{
    virtual vector<Person1> find_all_children_of(const string &name) = 0;
};

struct Relationships : RelationshipBrowser
{
    vector<tuple<Person1, Relationship, Person1>> relations;

    void add_parent_and_child(const Person1& parent, const Person1& child)
    {
        relations.push_back({parent, Relationship::parent, child});
        relations.push_back({child, Relationship::child, parent});
    }

    vector<Person1> find_all_children_of(const string &name) override {
        vector<Person1> result;

        for (auto && [first, rel, second] : relations)
        {
            if (first.name == name)
            {
                result.push_back(second);
            }
        }
        return result;

    }
};

struct Research
{
    Research(RelationshipBrowser &browser)
    {
        for (auto & child : browser.find_all_children_of("John"))
        {
            cout << "John has a child called " << child.name << endl;
        }
    }
//    Research(Relationships& relationships)
//    {
//        auto & relations = relationships.relations;
//        for (auto && [first, rel, second] : relations)
//        {
//            if (first.name == "John" && rel == Relationship::parent)
//            {
//                cout << "John has a child called " << second.name << endl;
//            }
//        }
//
//    }
};

void testDependencyIversion()
{
    Person1 parent{"John"};
    Person1 child1{"Chris"}, child2{"Matt"};

    Relationships relationships;
    relationships.add_parent_and_child(parent, child1);
    relationships.add_parent_and_child(parent, child2);

    Research _(relationships);

}