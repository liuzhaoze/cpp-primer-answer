/**
 * 关于下面的代码，请指出每一个变量的类型以及程序结束时它们各自的值。
 */

/**
 * 赋值是会产生引用的一类典型表达式，引用的类型是左值的类型。
 * 根据这一特点，请指出下面代码中每一个变量的类型和值。
 */

#include <iostream>

int main()
{
    int a = 3, b = 4;
    decltype(a) c = a;    // c 是 int
    decltype((b)) d = a;  // b 是 int & 与 a 绑定

    // a = 3, b = 4, c = 3, d = a = 3
    std::cout << a << " " << b << " "
              << c << " " << d << std::endl;
    ++c;
    // a = 3, b = 4, c = 4, d = a = 3
    std::cout << a << " " << b << " "
              << c << " " << d << std::endl;
    ++d;
    // a = 4, b = 4, c = 4, d = a = 4
    std::cout << a << " " << b << " "
              << c << " " << d << std::endl;

    decltype(a = b) e = a;  // e 是 int &

    return 0;
}
