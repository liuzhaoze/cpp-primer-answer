/**
 * 你在 7.5.1 节的练习 7.40 中曾经选择并编写了一个类，你认为它应该含有拷贝赋值运算符和移动赋值运算符吗？
 * 如果是，请实现它们。
 */

/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       14  Jan 2014
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
//
// Exercise 14.20:
// Define the addition and compound-assignment operators for your Sales_data class.
//
// Exercise 14.22:
// Define a version of the assignment operator that can assign a string representing
// an ISBN to a Sales_data.
//
// Exercise 14.23:
// Define an initializer_list assignment operator for your version of the StrVec
// class.
//
// Exercise 14.24:
// Decide whether the class you used in exercise 7.40 from § 7.5.1 (p. 291) needs a
// copy- and move-assignment operator. If so, define those operators.
//

#include "../../lib/Date.hpp"
#include <iostream>

int main()
{
    Date lhs(9999999), rhs(1);

    std::cout << (lhs -= 12000) << std::endl;

    return 0;
}
