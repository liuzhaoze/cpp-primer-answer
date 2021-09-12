/**
 * 在下述语句中，当赋值完成后 i 和 d 的值分别是多少？
 */

#include <iostream>

int main()
{
    int i;
    double d;

    d = i = 3.5;  // d = 3.0, i = 3
    std::cout << i << " " << d << std::endl;

    i = d = 3.5;  // d = 3.5, i = 3
    std::cout << i << " " << d << std::endl;

    return 0;
}
