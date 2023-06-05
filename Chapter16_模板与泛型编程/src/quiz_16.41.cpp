/**
 * 编写一个新的 sum 版本，它的返回类型保证足够大，足以容纳加法结果。
 */

#include <iostream>

template <typename T1, typename T2> auto sum(T1 lhs, T2 rhs) -> decltype(lhs + rhs)
{
    return lhs + rhs;
}

int main()
{
    std::cout << sum(1, 18446744073709551614u) << std::endl;

    std::cout << sum(9223372036854775807, 18446744073709551614u) << std::endl;

    return 0;
}
