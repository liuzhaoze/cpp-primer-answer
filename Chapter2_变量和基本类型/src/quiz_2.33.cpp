/**
 * 利用本节定义的变量，判断下列语句的运行结果。
 */

#include <iostream>

int main()
{
    int i = 0, &r = i;
    const int ci = i, &cr = ci;

    auto a = r;    // a 是整型变量（r 是 i 的别名）
    auto b = ci;   // b 是整型变量（ci 的顶层 const 被忽略了）
    auto c = cr;   // c 是整型变量（cr 是 ci 的别名，其他的跟变量 b 相同）
    auto d = &i;   // d 是指向整型变量的指针
    auto e = &ci;  // e 是指向整型常量的指针
    auto &g = ci;  // g 是整型常量的引用，绑定到 ci

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << d << std::endl;
    std::cout << e << std::endl;
    std::cout << g << std::endl;
    std::cout << "-----------------" << std::endl;

    a = 42;  // a 赋值为 42
    b = 42;  // b 赋值为 42
    c = 42;  // c 赋值为 42
    // d = 42;  // 错误：不能对地址赋整型值
    // e = 42;  // 错误：不能对地址赋整数值
    // g = 42;  // 错误：不能修改整型常量的值

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;

    return 0;
}
