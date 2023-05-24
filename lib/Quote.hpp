#ifndef _QUOTE_HPP_
#define _QUOTE_HPP_

#include <cstddef>
#include <ostream>
#include <string>

// 表示按原价销售的书籍
class Quote;
// 用于保存折扣值和购买量的类，派生类使用这些数据可以实现不同的价格策略
class Disc_quote;
// 表示超过指定购买量后，全部享受折扣的类
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

class Disc_quote : public Quote
{
  protected:
    std::size_t quantity = 0; // 购买量
    double discount = 0.0;    // 折扣

  public:
    Disc_quote() = default;
    Disc_quote(const std::string &book, double price, std::size_t qty, double disc)
        : Quote(book, price), quantity(qty), discount(disc)
    {
    }

    double net_price(std::size_t) const = 0; // 纯虚函数，需要派生类各自定义含义
    void debug() const = 0;
};

// 15.4 节抽象基类之前所使用的 Bulk_quote 定义
// class Bulk_quote : public Quote
// {
//   private:
//     std::size_t min_qty = 0; // 可以打折的最低购买量
//     double discount = 0.0;   // 折扣

//   public:
//     Bulk_quote() = default;
//     Bulk_quote(const std::string &book, double p, std::size_t qty, double disc)
//         : Quote(book, p), min_qty(qty), discount(disc)
//     {
//     }

//     double net_price(std::size_t) const override;
//     void debug() const override;
// };

class Bulk_quote : Disc_quote
{
  public:
    Bulk_quote() = default;
    Bulk_quote(const std::string &book, double price, std::size_t qty, double disc) : Disc_quote(book, price, qty, disc)
    {
    }

    double net_price(std::size_t) const override;
    void debug() const override;
};

double print_total(std::ostream &, const Quote &, std::size_t);

#endif
