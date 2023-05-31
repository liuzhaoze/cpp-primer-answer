#ifndef _QUOTE_HPP_
#define _QUOTE_HPP_

#include <cstddef>
#include <iostream>
#include <ostream>
#include <string>
#include <utility>

// 表示按原价销售的书籍
class Quote;
// 用于保存折扣值和购买量的类，派生类使用这些数据可以实现不同的价格策略
class Disc_quote;
// 表示超过指定购买量后，全部享受折扣的类
class Bulk_quote;

class Quote
{
    friend bool operator==(const Quote &, const Quote &);
    friend bool operator!=(const Quote &, const Quote &);

  private:
    std::string bookNo; // 书籍的 ISBN

  protected:
    double price = 0.0; // 书籍的原价

  public:
    // 默认构造函数
    Quote()
    {
        std::cout << "Quote:\tdefault constructor" << std::endl;
    }
    // 构造函数
    Quote(const std::string &book, double sales_price) : bookNo(book), price(sales_price)
    {
        std::cout << "Quote:\tconstructor taking 2 parameters" << std::endl;
    }
    // 析构函数
    virtual ~Quote()
    {
        std::cout << "Quote:\tdestructor" << std::endl;
    }
    // 拷贝构造函数
    Quote(const Quote &q) : bookNo(q.bookNo), price(q.price)
    {
        std::cout << "Quote:\tcopy constructor" << std::endl;
    }
    // 移动构造函数
    Quote(Quote &&q) noexcept : bookNo(std::move(q.bookNo)), price(std::move(q.price))
    {
        std::cout << "Quote:\tmove constructor" << std::endl;
    }
    // 拷贝赋值运算符
    Quote &operator=(const Quote &);
    // 移动赋值运算符
    Quote &operator=(Quote &&) noexcept;

    std::string isbn() const;
    virtual double net_price(std::size_t) const;
    virtual void debug() const;
};

bool operator==(const Quote &, const Quote &);
bool operator!=(const Quote &, const Quote &);

class Disc_quote : public Quote
{
    friend bool operator==(const Disc_quote &, const Disc_quote &);
    friend bool operator!=(const Disc_quote &, const Disc_quote &);

  protected:
    std::size_t quantity = 0; // 购买量
    double discount = 0.0;    // 折扣

  public:
    // 默认构造函数
    Disc_quote()
    {
        std::cout << "Disc_quote:\tdefault constructor" << std::endl;
    }
    // 构造函数
    Disc_quote(const std::string &book, double price, std::size_t qty, double disc)
        : Quote(book, price), quantity(qty), discount(disc)
    {
        std::cout << "Disc_quote:\tconstructor taking 4 parameters" << std::endl;
    }
    // 析构函数
    ~Disc_quote() override
    {
        std::cout << "Disc_quote:\tdestructor" << std::endl;
    }
    // 拷贝构造函数
    Disc_quote(const Disc_quote &dq) : Quote(dq), quantity(dq.quantity), discount(dq.discount)
    {
        std::cout << "Disc_quote:\tcopy constructor" << std::endl;
    }
    // 移动构造函数
    Disc_quote(Disc_quote &&dq) noexcept
        : Quote(std::move(dq)), quantity(std::move(dq.quantity)), discount(std::move(dq.discount))
    {
        std::cout << "Disc_quote:\tmove constructor" << std::endl;
    }
    // 拷贝赋值运算符
    Disc_quote &operator=(const Disc_quote &);
    // 移动赋值运算符
    Disc_quote &operator=(Disc_quote &&) noexcept;

    double net_price(std::size_t) const override = 0; // 纯虚函数，需要派生类各自定义含义
    void debug() const override = 0;
};

bool operator==(const Disc_quote &, const Disc_quote &);
bool operator!=(const Disc_quote &, const Disc_quote &);

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

class Bulk_quote : public Disc_quote
{
  public:
    // 默认构造函数
    Bulk_quote()
    {
        std::cout << "Bulk_quote:\tdefault constructor" << std::endl;
    }
    // 构造函数
    Bulk_quote(const std::string &book, double price, std::size_t qty, double disc) : Disc_quote(book, price, qty, disc)
    {
        std::cout << "Bulk_quote:\tconstructor taking 4 parameters" << std::endl;
    }
    // 析构函数
    ~Bulk_quote() override
    {
        std::cout << "Bulk_quote:\tdestructor" << std::endl;
    }
    // 拷贝构造函数
    Bulk_quote(const Bulk_quote &bq) : Disc_quote(bq)
    {
        std::cout << "Bulk_quote:\tcopy constructor" << std::endl;
    }
    // 移动构造函数
    Bulk_quote(Bulk_quote &&bq) noexcept : Disc_quote(std::move(bq))
    {
        std::cout << "Bulk_quote:\tmove constructor" << std::endl;
    }
    // 拷贝赋值运算符
    Bulk_quote &operator=(const Bulk_quote &);
    // 移动赋值运算符
    Bulk_quote &operator=(Bulk_quote &&) noexcept;

    double net_price(std::size_t) const override;
    void debug() const override;
};

double print_total(std::ostream &, const Quote &, std::size_t);

#endif
