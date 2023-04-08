/**
 * 编写一个 lambda ，接受两个 int ，返回它们的和。
 */

#include <iostream>

int main()
{
    auto f = [](int a, int b) { return a + b; };

    std::cout << f(1, 2) << std::endl;

    return 0;
}
