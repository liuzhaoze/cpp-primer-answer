/**
 * 改写你在 15.2.2 节练习中编写的数量受限的折扣策略，令其继承 Disc_quote 。
 */

#include "../../lib/Quote.hpp"

class Limit_quote : public Disc_quote
{
  public:
    Limit_quote() = default;
    Limit_quote(const std::string &book, double p, std::size_t qty, double disc) : Disc_quote(book, p, qty, disc)
    {
    }

    double net_price(std::size_t n) const override
    {
        if (n > quantity)
        {
            return quantity * price * (1 - discount) + (n - quantity) * price;
        }
        else
        {
            return n * (1 - discount) * price;
        }
    }
};
