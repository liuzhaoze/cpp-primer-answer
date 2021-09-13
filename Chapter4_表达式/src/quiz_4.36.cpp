/**
 * 假设 i 是 int 类型， d 是 double 类型，
 * 书写表达式 i *= d 使其执行整数类型的乘法而非浮点类型的乘法。
 */

#include <iostream>

int main()
{
    int i = 5;
    double d = 3.14159;

    i *= static_cast<int>(d);

    std::cout << i << std::endl;

    return 0;
}
