/**
 * 确定在你的 Person 类中是否有一些构造函数应该是 explicit 的。
 */

#ifndef QUIZ_7_50_HPP
#define QUIZ_7_50_HPP

#include <string>
#include <iostream>

struct Person
{
    friend std::istream &read(std::istream &is, Person &person);
    friend std::ostream &print(std::ostream &os, const Person &person);

public:
    Person() = default;
    Person(const std::string sname, const std::string saddr) : name(sname), address(saddr) {}
    explicit Person(std::istream &is) { read(is, *this); }

    std::string getName() const { return name; }
    std::string getAddress() const { return address; }

private:
    std::string name;
    std::string address;
};

std::istream &read(std::istream &is, Person &person)
{
    is >> person.name >> person.address;
    return is;
}

std::ostream &print(std::ostream &os, const Person &person)
{
    os << person.name << " " << person.address;
    return os;
}

#endif
