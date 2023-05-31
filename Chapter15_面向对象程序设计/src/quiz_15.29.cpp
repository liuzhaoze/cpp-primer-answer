/**
 * 再运行一次你的程序，这次传入 Quote 对象的 shared_ptr 。
 * 如果这次计算出的总额与之前的程序不一致，解释为什么；如果一致，也请说明原因。
 */

#include "../../lib/Quote.hpp"
#include <iostream>
#include <memory>
#include <vector>

int main()
{
    std::vector<std::shared_ptr<Quote>> vec;

    for (unsigned i = 1; i != 10; ++i)
    {
        vec.push_back(std::make_shared<Bulk_quote>("sss", i * 10.1, 10, 0.3));
    }

    double sum = 0.0;

    for (auto p : vec)
    {
        sum += p->net_price(20);
    }

    std::cout << sum << std::endl;
    // 不一致，因为上一题调用的是 Quote 的 net_price ，而本题动态绑定，调用的是 Bulk_quote 的 net_price

    return 0;
}
