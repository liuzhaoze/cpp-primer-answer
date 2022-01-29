#ifndef QUIZ_7_11_HPP
#define QUIZ_7_11_HPP

#include <string>
#include <iostream>

struct Sales_data
{
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

    Sales_data() = default;
    Sales_data(const std::string &s) : bookNo(s) {}
    Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p * n) {}
    Sales_data(std::istream &is);

    Sales_data &combine(const Sales_data &rhs)
    {
        this->units_sold += rhs.units_sold;
        this->revenue += rhs.revenue;
        return *this;
    }

    std::string isbn(void) const
    {
        return this->bookNo;
    }
};

Sales_data add(const Sales_data &lhs, const Sales_data &rhs);
std::istream &read(std::istream &is, Sales_data &item);
std::ostream &print(std::ostream &os, const Sales_data &item);

#endif
