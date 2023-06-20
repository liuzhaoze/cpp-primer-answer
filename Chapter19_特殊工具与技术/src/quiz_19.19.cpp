/**
 * 编写一个函数，令其接受 vector<Sales_data> 并查找平均价格高于某一个值的第一个元素。
 */

#include "../../lib/Sales_data.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

int main()
{
    std::ifstream in_file("../data/book_sales");
    std::vector<Sales_data> record;

    Sales_data item;
    while (in_file >> item)
    {
        if (record.empty())
        {
            record.push_back(item);
        }
        else
        {
            if (record.back().isbn() == item.isbn())
            {
                record.back() += item;
            }
            else
            {
                record.push_back(item);
            }
        }
    }

    std::for_each(record.begin(), record.end(), [](const auto &item) { std::cout << item << std::endl; });

    constexpr double base_price = 40.0;
    auto result = std::find_if(record.begin(), record.end(),
                               [base_price](const Sales_data &item) { return item.avg_price() > base_price; });
    if (result != record.end())
    {
        std::cout << "Target item: " << *result << std::endl;
    }

    return 0;
}
