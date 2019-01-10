#pragma once

#include "../../common.h"

class HtmlBuilder;
class HtmlElement;

class HtmlBuilder
{
public:
    unique_ptr<HtmlElement> root;

    HtmlBuilder(string root_name);

    HtmlBuilder& add_child(string child_name, string child_text);

    string str() const;

    operator HtmlElement() const;

    HtmlElement build();
};

class HtmlElement
{
    friend class HtmlBuilder;

    string name;
    string text;
    vector <HtmlElement> elements;

    const size_t indent_size = 2;

    HtmlElement() {}

    HtmlElement(const string &name, const string &text) : name(name), text(text) {}

public:
    string str(int indent = 0) const
    {
        ostringstream oss;
        string i(indent_size * indent, ' ');
        oss << i << "<" << name << ">" << endl;
        if (text.size() > 0)
            oss << string (indent_size*(indent + 1), ' ') << text << endl;

        for (const auto & e : elements)
            oss << e.str(indent + 1);

        oss << i << "</" << name << ">" << endl;

        return oss.str();
    }

    static HtmlBuilder create(string root_name)
    {
        return {root_name};
    }
};

HtmlBuilder::HtmlBuilder(string root_name)
        :root(new HtmlElement())
{
    root->name = root_name;
}

HtmlBuilder &HtmlBuilder::add_child(string child_name, string child_text)
{
    HtmlElement elem(child_name, child_text);
    root->elements.emplace_back(elem);
    return *this;
}

string HtmlBuilder::str() const {
        return root->str();
}

HtmlBuilder::operator HtmlElement() const {
    return *root;
}

HtmlElement HtmlBuilder::build() {
    return *root;
}

void testBuilder()
{
    auto text = "hello";
    string output;
    output += string("<p>") + text + "</p>";

    cout << output << endl;

    string words[] = {"hello", "world"};
    ostringstream oss;
    oss << "<ul>";
    for (auto w : words)
        oss << "  <li>" << w << "</li>";
    oss << "  </ul>" << endl;

    cout << oss.str();

    HtmlBuilder builder("ul");
    builder.add_child("li", "hello").add_child("li", "world");

    cout << builder.str();

    HtmlElement elem = HtmlElement::create("ul").add_child("", "");
}
