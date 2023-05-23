/**
 * 定义一个类使其实现一种数量受限的折扣策略，具体策略是：
 * 当购买书籍的数量不超过一个给定的限量时享受折扣，
 * 如果购买量一旦超过了限量，则超出的部分将以原价销售。
 */

#ifndef _QUIZ_15_7_HPP_
#define _QUIZ_15_7_HPP_

#include "../../lib/Quote.hpp"
#include <cstddef>
#include <string>

class Limit_quote : public Quote
{
  private:
    std::size_t max_qty = 0;
    double discount = 0.0;

  public:
    Limit_quote() = default;
    Limit_quote(const std::string &book, double p, std::size_t qty, double disc)
        : Quote(book, p), max_qty(qty), discount(disc)
    {
    }

    double net_price(std::size_t n) const override
    {
        if (n > max_qty)
        {
            return max_qty * price * (1 - discount) + (n - max_qty) * price;
        }
        else
        {
            return n * (1 - discount) * price;
        }
    }
};

#endif
