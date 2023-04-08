/**
 * 编写一个 lambda ，捕获它所在函数的 int ，并接受一个 int 参数。
 * lambda 应该返回捕获的 int 和 int 参数的和。
 */

#include <iostream>

int main()
{
    int capture = 1;
    auto f = [capture](int param) { return capture + param; };

    std::cout << f(5) << std::endl;

    return 0;
}
