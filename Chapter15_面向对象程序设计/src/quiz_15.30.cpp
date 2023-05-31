/**
 * 编写你自己的 Basket 类，用它计算上一个练习中交易记录的总价格。
 */

#include "../../lib/Basket.hpp"
#include <iostream>

int main()
{
    Basket basket;

    for (unsigned i = 0; i != 10; ++i)
    {
        basket.add_item(Bulk_quote("Bible", 20.6, 20, 0.3));
    }

    for (unsigned i = 0; i != 10; ++i)
    {
        basket.add_item(Bulk_quote("C++Primer", 30.9, 5, 0.4));
    }

    for (unsigned i = 0; i != 10; ++i)
    {
        basket.add_item(Quote("CLRS", 40.1));
    }

    basket.print_receipt(std::cout);

    return 0;
}
