#include "Sales_data.hpp"
#include <ostream>

/**
 * @brief 将销售记录加入本销售记录中
 *
 * @param rhs
 * @return Sales_data&
 */
Sales_data &Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;

    return *this;
}

/**
 * @brief 返回平均售价
 *
 * @return double
 */
double Sales_data::avg_price() const
{
    if (units_sold != 0)
    {
        return revenue / units_sold;
    }
    else
    {
        return 0;
    }
}

/**
 * @brief 从输入流中读取ISBN、销售数量、单价
 *
 * @param istrm
 * @param item
 * @return std::istream&
 */
std::istream &read(std::istream &istrm, Sales_data &item)
{
    double price = 0;

    istrm >> item.book_No >> item.units_sold >> price;
    item.revenue = price * item.units_sold;

    return istrm;
}

/**
 * @brief 输出销售记录的ISBN、销售数量、收入、平均价格
 *
 * @param ostrm
 * @param item
 * @return std::ostream&
 */
std::ostream &print(std::ostream &ostrm, const Sales_data &item)
{
    ostrm << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();

    return ostrm;
}

/**
 * @brief 将两个销售记录相加，并返回相加结果
 *
 * @param lhs
 * @param rhs
 * @return Sales_data
 */
Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;

    sum.combine(rhs);

    return sum;
}

inline bool compare_isbn(const Sales_data &lhs, const Sales_data &rhs)
{
    return lhs.isbn() < rhs.isbn();
}
