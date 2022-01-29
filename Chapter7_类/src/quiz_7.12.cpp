/**
 * 把只接受一个 istream 作为参数的构造函数定义移到类的内部。
 */
#include "quiz_7.12.hpp"

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

std::istream &read(std::istream &is, Sales_data &item)
{
    double price = 0;
    std::cout << "ISBN / units_sold / price" << std::endl;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " "
       << item.revenue;

    return os;
}
