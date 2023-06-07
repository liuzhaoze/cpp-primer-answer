/**
 * 定义你自己版本的 hash<Sales_data> ，并定义一个 Sales_data 对象的 unordered_multiset 。
 * 将多条交易记录保存到容器中，并打印其内容。
 */

#include "../../lib/Sales_data.hpp"
#include <iostream>
#include <unordered_set>

int main()
{
    std::unordered_multiset<Sales_data> mset;
    Sales_data sd("Bible", 10, 0.98);

    mset.emplace(sd);
    mset.emplace("C++ Primer", 5, 9.99);

    for (const auto &item : mset)
    {
        std::cout << item << std::endl;
        std::cout << "the hash code of " << item.isbn() << ":\n0x" << std::hex << std::hash<Sales_data>()(item)
                  << std::endl;
    }

    return 0;
}
