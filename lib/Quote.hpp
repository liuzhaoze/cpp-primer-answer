#ifndef _QUOTE_HPP_
#define _QUOTE_HPP_

#include <cstddef>
#include <ostream>
#include <string>

// 表示按原价销售的书籍
class Quote;
// 表示可以打折销售的书籍
class Bulk_quote;

class Quote
{
  private:
    std::string bookNo; // 书籍的 ISBN

  protected:
    double price = 0.0; // 书籍的原价

  public:
    Quote() = default;
    Quote(const std::string &book, double sales_price) : bookNo(book), price(sales_price)
    {
    }
    virtual ~Quote() = default;

    std::string isbn() const;
    virtual double net_price(std::size_t) const;
    virtual void debug() const;
};

class Bulk_quote : public Quote
{
  private:
    std::size_t min_qty = 0; // 可以打折的最低购买量
    double discount = 0.0;   // 折扣

  public:
    Bulk_quote() = default;
    Bulk_quote(const std::string &book, double p, std::size_t qty, double disc)
        : Quote(book, p), min_qty(qty), discount(disc)
    {
    }

    double net_price(std::size_t) const override;
    void debug() const override;
};

double print_total(std::ostream &, const Quote &, std::size_t);

#endif
