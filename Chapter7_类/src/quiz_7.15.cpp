/**
 * 为你的 Person 类添加正确的构造函数。
 */

#include "quiz_7.15.hpp"

std::string Person::get_name(void) const
{
    return this->name;
}

std::string Person::get_address(void) const
{
    return this->address;
}

std::istream &read(std::istream &is, Person &p)
{
    is >> p.name >> p.address;
    return is;
}

std::ostream &print(std::ostream &os, const Person &p)
{
    os << p.get_name() << " " << p.get_address();
    return os;
}
