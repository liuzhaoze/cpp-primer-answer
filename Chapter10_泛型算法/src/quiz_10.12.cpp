/**
 * 编写名为 compareIsbn 的函数，比较两个 Sales_data 对象的 isbn() 成员。
 * 使用这个函数排序一个保存 Sales_data 对象的 vector 。
 */

#include "../../lib/Sales_data.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

inline void print_vector(const std::vector<Sales_data> &svec)
{
    for (const auto &i : svec)
    {
        print(std::cout, i) << std::endl;
    }
}

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
    return lhs.isbn() < rhs.isbn();
}

int main()
{
    std::ifstream ifstrm("../data/book_sales");
    std::vector<Sales_data> svec;
    Sales_data s;

    while (read(ifstrm, s))
    {
        if (!svec.empty() && svec.back().isbn() == s.isbn())
        {
            svec.back().combine(s);
        }
        else
        {
            svec.push_back(s);
        }
    }

    std::cout << "Original:" << std::endl;
    print_vector(svec);

    std::sort(svec.begin(), svec.end(), compareIsbn);
    std::cout << "Sorted:" << std::endl;
    print_vector(svec);

    return 0;
}
