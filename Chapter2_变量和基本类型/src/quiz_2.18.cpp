/**
 * 编写代码分别更改指针的值以及指针所指对象的值。
 */

#include <iostream>

int main()
{
    int a = 1, b = 2;
    int *p = &a;

    std::cout << a << " " << b << std::endl;

    p = &b;   // 更改指针的值
    *p = 10;  // 更改指针所指对象的值

    std::cout << a << " " << b << std::endl;

    return 0;
}
