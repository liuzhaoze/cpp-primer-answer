/**
 * 假定 vi 是一个保存 int 的容器，其中有偶数值也有奇数值，
 * 分析下面循环的行为，然后编写程序验证你的分析是否正确。
 */

#include "../../lib/print_container.hpp"
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    auto iter = vi.begin();
    while (iter != vi.end())
    {
        if (*iter % 2)
        {
            iter = vi.insert(iter, *iter);
            // 遇到奇数后，在该数前面插入这个奇数
            // 并将 iter 指向它
            print_container(std::cout, vi.cbegin(), vi.cend()) << std::endl;
        }
        ++iter; // iter 指回原来的奇数
    }
    // 程序会陷入死循环，不断地插入第一次遇到的奇数

    return 0;
}
