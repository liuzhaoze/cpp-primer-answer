#include "Quote.hpp"
#include <iostream>
#include <string>
#include <utility>

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

Quote *Quote::clone() const &
{
    return new Quote(*this);
}

Quote *Quote::clone() &&
{
    return new Quote(std::move(*this));
}

double Bulk_quote::net_price(std::size_t n) const
{
    if (n >= quantity)
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
              << "\tbookNo= " << isbn() << "\n\tprice= " << price << "\n\tmin_qty= " << quantity
              << "\n\tdiscount= " << discount << std::endl;
}

Bulk_quote *Bulk_quote::clone() const &
{
    return new Bulk_quote(*this);
}

Bulk_quote *Bulk_quote::clone() &&
{
    return new Bulk_quote(std::move(*this));
}

double print_total(std::ostream &os, const Quote &item, std::size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << std::endl;

    return ret;
}

bool operator==(const Quote &lhs, const Quote &rhs)
{
    return (lhs.bookNo == rhs.bookNo) && (lhs.price == rhs.price);
}

bool operator!=(const Quote &lhs, const Quote &rhs)
{
    return !(lhs == rhs);
}

bool operator==(const Disc_quote &lhs, const Disc_quote &rhs)
{
    return (Quote(lhs) == Quote(rhs)) && (lhs.quantity == rhs.quantity) && (lhs.discount == rhs.discount);
}

bool operator!=(const Disc_quote &lhs, const Disc_quote &rhs)
{
    return !(lhs == rhs);
}

Quote &Quote::operator=(const Quote &rhs)
{
    if (*this != rhs)
    {
        bookNo = rhs.bookNo;
        price = rhs.price;
    }

    std::cout << "Quote:\tcopy operator" << std::endl;

    return *this;
}

Quote &Quote::operator=(Quote &&rhs) noexcept
{
    if (*this != rhs)
    {
        bookNo = std::move(rhs.bookNo);
        price = std::move(rhs.price);
    }

    std::cout << "Quote:\tmove operator" << std::endl;

    return *this;
}

Disc_quote &Disc_quote::operator=(const Disc_quote &rhs)
{
    if (*this != rhs)
    {
        Quote::operator=(rhs);
        quantity = rhs.quantity;
        discount = rhs.discount;
    }

    std::cout << "Disc_quote:\tcopy operator" << std::endl;

    return *this;
}

Disc_quote &Disc_quote::operator=(Disc_quote &&rhs) noexcept
{
    if (*this != rhs)
    {
        Quote::operator=(std::move(rhs));
        quantity = std::move(rhs.quantity);
        discount = std::move(rhs.discount);
    }

    std::cout << "Disc_quote:\tmove operator" << std::endl;

    return *this;
}

Bulk_quote &Bulk_quote::operator=(const Bulk_quote &rhs)
{
    if (*this != rhs)
    {
        Disc_quote::operator=(rhs);
    }

    std::cout << "Bulk_quote:\tcopy operator" << std::endl;

    return *this;
}

Bulk_quote &Bulk_quote::operator=(Bulk_quote &&rhs) noexcept
{
    if (*this != rhs)
    {
        Disc_quote::operator=(std::move(rhs));
    }

    std::cout << "Bulk_quote:\tmove operator" << std::endl;

    return *this;
}
