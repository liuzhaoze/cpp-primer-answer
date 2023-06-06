/**
 * 定义上一个练习中的函数，令它们打印一条身份信息。
 * 运行该练习中的代码。
 * 如果函数调用的行为与你预期不符，确定你理解了原因。
 */

#include <iostream>

template <typename T> void f(T)
{
    std::cout << "f(T)" << std::endl;
}

template <typename T> void f(const T *)
{
    std::cout << "f(const T *)" << std::endl;
}

template <typename T> void g(T)
{
    std::cout << "g(T)" << std::endl;
}

template <typename T> void g(T *)
{
    std::cout << "g(T *)" << std::endl;
}

int main()
{
    int i = 42;
    int *ip = &i;
    const int ci = 0;
    const int *cip = &ci;

    g(42);
    g(ip);
    g(ci);
    g(cip);
    f(42);
    f(ip);
    f(ci);
    f(cip);

    return 0;
};
