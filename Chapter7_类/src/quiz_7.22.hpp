#ifndef QUIZ_7_22_HPP
#define QUIZ_7_22_HPP

#include <string>
#include <iostream>

class Person
{
    friend std::istream &read(std::istream &is, Person &p);

private:
    std::string name;
    std::string address;

public:
    Person() : name(""), address("") {}
    Person(std::string n, std::string a) : name(n), address(a) {}

    std::string get_name(void) const;
    std::string get_address(void) const;
};

std::istream &read(std::istream &is, Person &p);
std::ostream &print(std::ostream &os, const Person &p);

#endif
