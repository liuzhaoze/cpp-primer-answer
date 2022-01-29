#ifndef QUIZ_7_9_HPP
#define QUIZ_7_9_HPP

#include <string>
#include <iostream>

struct Person
{
    std::string name;
    std::string address;

    std::string get_name(void) const;
    std::string get_address(void) const;
};

std::istream &read(std::istream &is, Person &p);
std::ostream &print(std::ostream &os, const Person &p);

#endif
