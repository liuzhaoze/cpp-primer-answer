#include "Quote.hpp"
#include <iostream>
#include <string>

std::string Quote::isbn() const
{
    return bookNo;
}

double Quote::net_price(std::size_t n) const
{
    return n * price;
}

void Quote::debug() const
{
    std::cout << "Class= Quote\n"
              << "\tbookNo= " << bookNo << "\n\tprice= " << price << std::endl;
}

double Bulk_quote::net_price(std::size_t n) const
{
    if (n >= min_qty)
    {
        return n * (1 - discount) * price;
    }
    else
    {
        return n * price;
    }
}

void Bulk_quote::debug() const
{
    std::cout << "Class= Bulk_quote\n"
              << "\tbookNo= " << isbn() << "\n\tprice= " << price << "\n\tmin_qty= " << min_qty
              << "\n\tdiscount= " << discount << std::endl;
}

double print_total(std::ostream &os, const Quote &item, std::size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << std::endl;

    return ret;
}
