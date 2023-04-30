/**
 * 用 allocator 重写下面的程序。
 */

#define TOGGLE 0
#include <cstddef>
#include <iostream>
#include <memory>
#include <string>

const std::size_t n = 5;

#if TOGGLE

int main()
{
    std::string *const p = new std::string[n]; // 构造 n 个空 string
    std::string s;
    std::string *q = p; // q 指向第一个 string

    while (std::cin >> s && q != p + n)
    {
        *q++ = s; // 赋予 *q 一个新值
    }

    const std::size_t size = q - p;

    for (std::size_t i = 0; i != size; ++i)
    {
        std::cout << p[i] << std::endl;
    }

    delete[] p;
    return 0;
}

#else

int main()
{
    std::allocator<std::string> alloc;
    auto const p = alloc.allocate(n); // 分配可以容纳 n 个 string 的内存空间
    std::string s;
    auto q = p; // q 指向已构造内存的尾后位置

    while (std::cin >> s && q != p + n)
    {
        alloc.construct(q++, s); // 使用 s 的值在 q 所指内存构造对象
    }

    for (std::size_t i = 0, size = q - p; i != size; ++i)
    {
        std::cout << p[i] << std::endl;
    }

    while (q != p)
    {
        alloc.destroy(--q); // 析构 string
    }

    alloc.deallocate(p, n); // 释放内存
    return 0;
}

#endif
