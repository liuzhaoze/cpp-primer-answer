/**
 * 标准库 max 函数有两个参数，它返回实参中的较大者。
 * 此函数有一个模板类型参数。
 * 你能在调用 max 时传递给它一个 int 和一个 double 吗？
 * 如果可以，如何做？如果不可以，为什么？
 */

#include <algorithm>
#include <iostream>

int main()
{
    int i = 9000;
    double d = 3.1415926;

    // std::max(i, d); // 不能通过推断实例化 max 函数
    auto m = std::max<double>(i, d); // 需要指定显式实参

    std::cout << m << std::endl;

    return 0;
}
