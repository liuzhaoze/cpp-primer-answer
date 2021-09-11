/**
 * 写出一条表达式用于确定一个整数是奇数还是偶数。
 */

#include <iostream>

int main()
{
    int num = 0;

    while (std::cin >> num) {
        if (num % 2) {
            std::cout << "the number is odd." << std::endl;
        }
        else {
            std::cout << "the number is even." << std::endl;
        }
    }

    return 0;
}
