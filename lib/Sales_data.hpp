#ifndef _SALES_DATA_HPP_
#define _SALES_DATA_HPP_

#include <iostream>
#include <string>

class Sales_data
{
    friend Sales_data add(const Sales_data &, const Sales_data &);
    friend std::ostream &print(std::ostream &, const Sales_data &);
    friend std::istream &read(std::istream &, Sales_data &);

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
    Sales_data &combine(const Sales_data &);
    double avg_price() const;
};

Sales_data add(const Sales_data &, const Sales_data &);
std::ostream &print(std::ostream &, const Sales_data &);
std::istream &read(std::istream &, Sales_data &);

inline bool compare_isbn(const Sales_data &lhs, const Sales_data &rhs);

#endif
