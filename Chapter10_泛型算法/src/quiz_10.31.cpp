/**
 * 修改前一题的程序，使其只打印不重复的元素。
 * 你的程序应使用 unique_copy 。
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

    std::unique_copy(ivec.begin(), ivec.end(), out_iter);
    std::cout << std::endl;

    return 0;
}
