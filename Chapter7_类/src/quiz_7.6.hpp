#ifndef QUIZ_7_6_HPP
#define QUIZ_7_6_HPP

#include "quiz_7.2.hpp"
#include <iostream>

Sales_data add(const Sales_data &lhs, const Sales_data &rhs);
std::istream &read(std::istream &is, Sales_data &item);
std::ostream &print(std::ostream &os, const Sales_data &item);

#endif
