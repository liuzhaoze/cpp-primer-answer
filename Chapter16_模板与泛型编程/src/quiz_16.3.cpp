/**
 * 对两个 Sales_data 对象调用你的 compare 函数，观察编译器在实例化过程中如何处理错误。
 */

#include "../../lib/Sales_data.hpp"
#include <iostream>

template <typename T> int compare(const T &v1, const T &v2)
{
    if (v1 < v2)
    {
        return -1;
    }
    if (v2 < v1)
    {
        return 1;
    }
    return 0;
}

int main()
{
    Sales_data sd1("a"), sd2("b");

    std::cout << compare(sd1, sd2) << std::endl;

    return 0;
}
