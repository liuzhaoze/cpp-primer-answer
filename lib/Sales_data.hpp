#ifndef _SALES_DATA_HPP_
#define _SALES_DATA_HPP_

#include <cstddef>
#include <functional>
#include <iostream>
#include <istream>
#include <ostream>
#include <stdexcept>
#include <string>

class Sales_data
{
  public:
    friend struct std::hash<Sales_data>; // 允许 hash 类对 Sales_data 私有成员进行 hash

    friend Sales_data add(const Sales_data &, const Sales_data &);
    friend Sales_data operator+(const Sales_data &, const Sales_data &);
    friend Sales_data operator-(const Sales_data &, const Sales_data &);

    friend std::ostream &print(std::ostream &, const Sales_data &);
    friend std::ostream &operator<<(std::ostream &, const Sales_data &);
    friend std::istream &read(std::istream &, Sales_data &);
    friend std::istream &operator>>(std::istream &, Sales_data &);

    friend bool operator==(const Sales_data &, const Sales_data &);
    friend bool operator!=(const Sales_data &, const Sales_data &);

  private:
    std::string book_No;
    unsigned units_sold = 0;
    double revenue = 0.0;

  public:
    Sales_data() = default;
    Sales_data(const std::string &s) : book_No(s)
    {
    }
    Sales_data(const std::string &s, unsigned n, double p) : book_No(s), units_sold(n), revenue(p * n)
    {
    }
    Sales_data(std::istream &istrm)
    {
        read(istrm, *this);
    }

    std::string isbn() const
    {
        return book_No;
    }
    double avg_price() const;

    Sales_data &combine(const Sales_data &);
    Sales_data &operator+=(const Sales_data &);
    Sales_data &operator-=(const Sales_data &);

    Sales_data &operator=(const std::string &);

    explicit operator std::string() const
    {
        return book_No;
    }
    explicit operator double() const
    {
        return avg_price();
    }
};

Sales_data add(const Sales_data &, const Sales_data &);
Sales_data operator+(const Sales_data &, const Sales_data &);
Sales_data operator-(const Sales_data &, const Sales_data &);

std::ostream &print(std::ostream &, const Sales_data &);
std::ostream &operator<<(std::ostream &, const Sales_data &);
std::istream &read(std::istream &, Sales_data &);
std::istream &operator>>(std::istream &, Sales_data &);

bool operator==(const Sales_data &, const Sales_data &);
bool operator!=(const Sales_data &, const Sales_data &);
bool compare_isbn(const Sales_data &, const Sales_data &);

// 为 Sales_data 定义特例化的 hash 类
namespace std
{
template <> struct hash<Sales_data>
{
    using result_type = size_t;
    using argument_type = Sales_data; // 该类型需要定义 == 运算符
    size_t operator()(const Sales_data &) const;
};
} // namespace std

class out_of_stock : public std::runtime_error
{
  public:
    explicit out_of_stock(const std::string &s) : std::runtime_error(s)
    {
    }
};

class isbn_mismatch : public std::logic_error
{
  public:
    const std::string left, right;

    explicit isbn_mismatch(const std::string &s) : std::logic_error(s)
    {
    }
    isbn_mismatch(const std::string &s, const std::string &lhs, const std::string &rhs)
        : std::logic_error(s), left(lhs), right(rhs)
    {
    }
};

#endif
