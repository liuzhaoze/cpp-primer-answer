/**
 * 对于 7.1.2 节练习中的代码，添加读取和打印 Person 对象的操作。
 */

#include "quiz_7.9.hpp"

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
