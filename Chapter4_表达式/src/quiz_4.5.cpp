/**
 * 写出下列表达式的求值结果。
 */

#include <iostream>

int main()
{
    std::cout << -30 * 3 + 21 / 5 << std::endl;
    // -90 + 4 = -86

    std::cout << -30 + 3 * 21 / 5 << std::endl;
    // -30 + 12 = -18

    std::cout << 30 / 3 * 21 % 5 << std::endl;
    // 0

    std::cout << -30 / 3 * 21 % 4 << std::endl;
    // -2

    return 0;
}
