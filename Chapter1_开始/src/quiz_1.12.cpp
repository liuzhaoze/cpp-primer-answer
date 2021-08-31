/**
 * 下面的 for 循环完成了什么功能？
 * sum 的终值是多少？
 */

#include <iostream>

// 循环实现从 -100 加到 100
// sum 的终值是 0
int main()
{
    int sum = 0;
    for (int i = -100; i <= 100; ++i)
        sum += i;

    std::cout << sum << std::endl;

    return 0;
}
