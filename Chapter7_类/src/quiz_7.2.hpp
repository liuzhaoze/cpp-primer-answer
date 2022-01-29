/**
 * 曾在 2.6.2 节的练习中编写了一个 Sales_data 类，
 * 请向这个类添加 combine 和 isbn 成员。
 */

#ifndef QUIZ_7_2_HPP
#define QUIZ_7_2_HPP

#include <string>

struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

    Sales_data& combine(const Sales_data &rhs);
    std::string isbn(void) const;
};

Sales_data& Sales_data::combine(const Sales_data &rhs)
{
    this->units_sold += rhs.units_sold;
    this->revenue += rhs.revenue;
    return *this;
}

std::string Sales_data::isbn(void) const
{
    return this->bookNo;
}

#endif
