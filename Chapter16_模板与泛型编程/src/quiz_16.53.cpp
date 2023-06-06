/**
 * 编写你自己版本的 print 函数，并打印一个、两个及五个实参来测试它，要打印的每个实参都应有不同的类型。
 */

#include <iostream>
#include <ostream>

template <typename T> std::ostream &print(std::ostream &os, const T &t)
{
    return os << t;
}

template <typename T, typename... Args> std::ostream &print(std::ostream &os, const T &t, const Args &...rest)
{
    os << t << ", ";
    return print(os, rest...);
}

int main()
{
    print(std::cout, 1) << std::endl;
    print(std::cout, 1, 2) << std::endl;
    print(std::cout, 1, 2, 3, 4, "sss", 42.4242) << std::endl;

    return 0;
}
