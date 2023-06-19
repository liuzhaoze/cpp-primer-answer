/**
 * 使用 malloc 编写你自己的 operator new(size_t) 函数，
 * 使用 free 编写 operator delete(void *) 函数。
 */

#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <new>

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
    int *pi = new int(42);

    std::cout << *pi << std::endl;

    delete pi;

    return 0;
}
