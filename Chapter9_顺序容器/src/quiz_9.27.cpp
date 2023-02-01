/**
 * 编写程序，查找并删除 forward_list<int> 中的奇数元素。
 */

#include "../../lib/print_container.hpp"
#include <forward_list>
#include <iostream>

int main()
{
    std::forward_list<int> flist = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto prev = flist.before_begin(); // 首前迭代器
    auto curr = flist.begin();        // 第一个元素

    print_container(std::cout, flist.cbegin(), flist.cend()) << std::endl;

    while (curr != flist.end())
    {
        if (*curr % 2)
        {
            // 当前元素是奇数
            curr = flist.erase_after(prev);
            // 前驱不变，curr 指向删除元素后面的元素
        }
        else
        {
            // 当前元素是偶数
            prev = curr; // 前驱后移
            ++curr;      // curr 后移
        }
    }

    print_container(std::cout, flist.cbegin(), flist.cend()) << std::endl;

    return 0;
}
