/**
 * 下列表达式的结果是什么？
 */

#include <iostream>

int main()
{
    unsigned long ul1 = 3, ul2 = 7;

    // 0011 & 0111 = 0011
    std::cout << (ul1 & ul2) << std::endl;  // 3

    // 0011 | 0111 = 0111
    std::cout << (ul1 | ul2) << std::endl;  // 7

    std::cout << (ul1 && ul2) << std::endl;  // 1

    std::cout << (ul1 || ul2) << std::endl;  // 1

    return 0;
}
