/**
 * 重写上一题的函数，返回一个迭代器指向找到的元素。
 * 注意，程序必须处理未找到给定值的情况。
 */

/**
 * 编写函数，接受一对指向 vector<int> 的迭代器和一个 int 值。
 * 在两个迭代器指定的范围中查找给定的值，返回一个布尔值来指出是否找到。
 */

#include <iostream>
#include <ostream>
#include <vector>

std::vector<int>::const_iterator find_item(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end,
                                           int i)
{
    while (begin != end)
    {
        if (*begin == i)
        {
            return begin;
        }
        ++begin;
    }

    return end;
}

int main()
{
    std::vector<int> ivec = {1, 2, 3, 4, -5, -6, -7};

    auto it = find_item(ivec.cbegin(), ivec.cend(), 5);

    if (it != ivec.cend())
    {
        std::cout << *it << std::endl;
    }
    else
    {
        std::cout << "Not found." << std::endl;
    }

    return 0;
}
