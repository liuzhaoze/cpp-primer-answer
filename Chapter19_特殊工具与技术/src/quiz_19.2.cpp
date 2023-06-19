/**
 * 默认情况下，allocator 类使用 operator new 获取存储空间，然后使用 operator delete 释放它。
 * 利用上一题中的两个函数重新编译并运行你的 StrVec 程序。
 */

#include "../../lib/StrVec.hpp"
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <new>
#include <string>

void *operator new(size_t size)
{
    std::cout << "My new called" << std::endl;
    if (void *mem = malloc(size))
    {
        return mem;
    }
    else
    {
        throw std::bad_alloc();
    }
}

void operator delete(void *mem) noexcept
{
    std::cout << "My delete called" << std::endl;
    free(mem);
}

int main()
{
    StrVec sv;                   // StrVec 每次重新分配的空间是原来大小的 2 倍
    constexpr unsigned MAX = 32; // 1 2 4 8 16 32 一共分配 6 次

    for (unsigned i = 0; i != MAX; ++i)
    {
        std::cout << "count: " << i + 1 << std::endl;
        sv.push_back(std::to_string(i));
    }

    return 0;
}
