/**
 * 编写程序，从 cin 读取一组数，输出其和。
 */

#include <iostream>

int main()
{
    int sum = 0, value = 0;

    while (std::cin >> value)
        sum += value;

    std::cout << "Sum is: " << sum << std::endl;

    return 0;
}
