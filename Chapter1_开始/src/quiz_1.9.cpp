/**
 * 编写程序，使用 while 循环将 50 到 100 的整数相加。
 */

#include <iostream>

int main()
{
    int sum = 0, val = 50;

    while (val <= 100) {
        sum += val;
        ++val;
    }

    std::cout << "Sum of 50 to 100 inclusive is "
              << sum << std::endl;

    return 0;
}
