/**
 * 在下面的程序中，如果不将 insert 的结果赋予 begin ，将会发生什么？
 * 编写程序，去掉此赋值语句，验证你的答案。
 */

#define ORIGIN 0

#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto begin = v.begin();

#if ORIGIN

    while (begin != v.end())
    {
        ++begin;
        begin = v.insert(begin, 42);
        // 后移之后在元素前面插入 42
        ++begin; // 指向下一个元素
    }

#else

    while (begin != v.end())
    {
        ++begin;
        v.insert(begin, 42);
        ++begin;
        // 不将 insert 的结果赋给 begin ，会导致 begin 多向后移动一个元素
        // 程序会访问非法内存空间
    }

#endif

    for (auto i : v)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}
