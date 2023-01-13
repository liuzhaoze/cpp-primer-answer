/**
 * 编写函数，接受一对指向 vector<int> 的迭代器和一个 int 值。
 * 在两个迭代器指定的范围中查找给定的值，返回一个布尔值来指出是否找到。
 */

#include <iostream>
#include <ostream>
#include <vector>

bool is_item_exist(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end, int i)
{
    while (begin != end)
    {
        if (*begin == i)
        {
            return true;
        }
        ++begin;
    }

    return false;
}

int main()
{
    std::vector<int> ivec = {1, 2, 3, 4, -5, -6, -7};

    std::cout << is_item_exist(ivec.cbegin(), ivec.cend(), 4) << std::endl;
    std::cout << is_item_exist(ivec.cbegin(), ivec.cend(), 6) << std::endl;

    return 0;
}
