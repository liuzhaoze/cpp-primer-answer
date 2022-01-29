/**
 * 在你的 Person 类中提供一些操作使其能够返回姓名和住址。
 * 这些函数是否应该是 const 的呢？解释原因。
 */

#ifndef QUIZ_7_5_HPP
#define QUIZ_7_5_HPP

#include <string>

struct Person
{
    std::string name;
    std::string address;

    std::string get_name(void) const;
    std::string get_address(void) const;
};

std::string Person::get_name(void) const
{
    return this->name;
}

std::string Person::get_address(void) const
{
    return this->address;
}

#endif
