/**
 * 为 while 循环写一个条件，使其从标准输入中读取整数，
 * 遇到 42 时停止。
 */

#include <iostream>

int main()
{
    int num = 0;

    while (std::cin >> num && num != 42) {
        std::cout << "---" << num << std::endl;
    }

    return 0;
}
