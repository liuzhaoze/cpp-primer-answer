/**
 * 使用下面代码定义的 ia ，将 ia 拷贝到一个 vector 和一个 list 中。
 * 使用单迭代器版本的 erase 从 list 中删除奇数元素，从 vector 中删除偶数元素。
 */

#include "../../lib/print_container.hpp"
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

int main()
{
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    std::vector<int> ivec(std::begin(ia), std::end(ia));
    std::list<int> ilst(std::begin(ia), std::end(ia));

    std::cout << "Original ivec: ";
    print_container(std::cout, ivec.cbegin(), ivec.cend()) << std::endl;
    std::cout << "Original ilst: ";
    print_container(std::cout, ilst.cbegin(), ilst.cend()) << std::endl;

    auto iter1 = ivec.begin();
    while (iter1 != ivec.end())
    {
        if (*iter1 % 2)
        {
            ++iter1;
        }
        else
        {
            iter1 = ivec.erase(iter1);
        }
    }

    auto iter2 = ilst.begin();
    while (iter2 != ilst.end())
    {
        if (*iter2 % 2)
        {
            iter2 = ilst.erase(iter2);
        }
        else
        {
            ++iter2;
        }
    }

    std::cout << "Final vector: ";
    print_container(std::cout, ivec.cbegin(), ivec.cend()) << std::endl;
    std::cout << "Final list: ";
    print_container(std::cout, ilst.cbegin(), ilst.cend()) << std::endl;

    return 0;
}
