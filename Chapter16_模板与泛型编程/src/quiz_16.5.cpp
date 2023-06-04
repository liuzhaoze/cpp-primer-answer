/**
 * 编写一个模板版本的 print 函数，它接受一个数组的引用，能处理任意大小、任意元素类型的数组。
 */

#include <iostream>
#include <string>

template <typename Array> void print(Array const &array)
{
    for (auto const &i : array)
    {
        std::cout << i << std::endl;
    }
}

int main()
{
    std::string s[] = {"a", "bb", "ccc", "dddd"};
    char c[] = {'a', 'b', 'c', 'd'};
    int i[] = {1, 2, 3, 4};

    print(s);
    print(c);
    print(i);

    return 0;
}
