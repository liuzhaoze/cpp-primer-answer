/**
 * 执行下面的代码段将输出什么结果？
 */

#include <iostream>

int main()
{
    int i, &ri = i;
    i = 5;
    ri = 10;

    // 10 10
    std::cout << i << " " << ri << std::endl;

    return 0;
}
