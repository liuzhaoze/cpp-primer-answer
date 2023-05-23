#include "Quote.hpp"
#include <string>

std::string Quote::isbn() const
{
    return bookNo;
}

double Quote::net_price(std::size_t n) const
{
    return n * price;
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

double print_total(std::ostream &os, const Quote &item, std::size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << std::endl;

    return ret;
}
