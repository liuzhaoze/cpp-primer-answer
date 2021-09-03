/**
 * 请叙述下面这段代码的作用。
 */

#include <iostream>

int main()
{
    int i = 42;    // 定义变量 i 并初始化为 42
    int *p1 = &i;  // 将对象 i 的地址赋给指针 p1

    *p1 = *p1 * *p1;  // 将 p1 所指向的值的平方存入 p1 指向的内存中

    std::cout << i << std::endl; // 结果为 42 * 42 = 1764

    return 0;
}
