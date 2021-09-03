/**
 * 下面的程序合法吗？
 * 如果合法，它将输出什么？
 */

#include <iostream>

int main()
{
    int i = 100, sum = 0;
    for (int i = 0; i != 10; ++i)
        sum += i;

    // i = 100; sum = 45;
    // i 不是 10 ，是因为 i = 10 仅在 for 作用域生效
    std::cout << i << " " << sum << std::endl;

    return 0;
}
