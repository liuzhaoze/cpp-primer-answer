/**
 * 编写一个 lambda ，捕获一个局部 int 变量，并递减变量值，直至它变为 0 。
 * 一旦变量变为 0 ，再调用 lambda 应该不再递减变量。
 * lambda 应该返回一个 bool 值，指出捕获的变量是否为 0 。
 */

#include <iostream>

int main()
{
    int i = 10;
    auto is_zero_decrease = [&i]() -> bool {
        if (i != 0)
        {
            --i;
        };
        return !i;
    };

    while (!is_zero_decrease())
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
