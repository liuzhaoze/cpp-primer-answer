/**
 * 使用流迭代器、sort 和 copy 从标准输入读取一个整数序列，将其排序，并将结果写到标准输出。
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main()
{
    std::istream_iterator<int> in_iter(std::cin), eof;
    std::ostream_iterator<int> out_iter(std::cout, " ");
    std::vector<int> ivec(in_iter, eof);

    std::sort(ivec.begin(), ivec.end());

    std::copy(ivec.begin(), ivec.end(), out_iter);
    std::cout << std::endl;

    return 0;
}
