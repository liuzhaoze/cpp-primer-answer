/**
 * 定义一个存放 Quote 对象的 vector ，将 Bulk_quote 对象传入其中。
 * 计算 vector 中所有元素总的 net_price 。
 */

#include "../../lib/Quote.hpp"
#include <iostream>
#include <vector>

int main()
{
    std::vector<Quote> vec;

    for (unsigned i = 1; i != 10; ++i)
    {
        vec.push_back(Bulk_quote("sss", i * 10.1, 10, 0.3));
    }

    double sum = 0.0;

    for (const auto &b : vec)
    {
        sum += b.net_price(20);
    }

    std::cout << sum << std::endl;

    return 0;
}
