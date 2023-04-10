/**
 * 重写 1.6 节中的书店程序，使用一个 vector 保存交易记录，使用不同算法完成处理。
 * 使用 sort 和 10.3.1 节中的 compareIsbn 函数来排序交易记录，然后使用 find 和 accumulate 求和。
 */

#include "../../lib/Sales_data.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

int main()
{
    std::ifstream ifstrm("../data/book_sales");
    std::istream_iterator<Sales_data> in_iter(ifstrm), eof;
    std::ostream_iterator<Sales_data> out_iter(std::cout);
    std::vector<Sales_data> vec(in_iter, eof);

    std::sort(vec.begin(), vec.end(), compare_isbn);

    for (auto beg = vec.cbegin(), end = beg; beg != vec.cend(); beg = end)
    {
        end = std::find_if(beg, vec.cend(), [beg](const Sales_data &item) { return item.isbn() != beg->isbn(); });
        std::cout << std::accumulate(beg, end, Sales_data(beg->isbn())) << std::endl;
    }

    return 0;
}
