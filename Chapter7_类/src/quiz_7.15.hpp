#ifndef QUIZ_7_15_HPP
#define QUIZ_7_15_HPP

#include <string>
#include <iostream>

struct Person
{
    std::string name;
    std::string address;

    Person() : name(""), address("") {}
    Person(std::string n, std::string a) : name(n), address(a) {}

    std::string get_name(void) const;
    std::string get_address(void) const;
};

std::istream &read(std::istream &is, Person &p);
std::ostream &print(std::ostream &os, const Person &p);

#endif
