/**
 * 重写 10.3.1 节练习 10.12 的程序，在对 sort 的调用中使用 lambda 来代替函数 compareIsbn 。
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

    std::sort(svec.begin(), svec.end(),
              [](const Sales_data &lhs, const Sales_data &rhs) { return lhs.isbn() < rhs.isbn(); });
    std::cout << "Sorted:" << std::endl;
    print_vector(svec);

    return 0;
}
