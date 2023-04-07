/**
 * 编写程序，使用 fill_n 将一个序列中的 int 值都设置为 0 。
 */

#include "../../lib/print_container.hpp"
#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> ivec = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    print_container(std::cout, ivec.cbegin(), ivec.cend()) << std::endl;

    std::fill_n(ivec.begin(), ivec.size(), 0);

    print_container(std::cout, ivec.cbegin(), ivec.cend()) << std::endl;

    return 0;
}
