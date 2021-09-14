/**
 * 使用逗号运算符重写 1.4.1 节的 while 循环，
 * 使它不再需要块，观察改写之后的代码的可读性提高了还是降低了。
 */

#include <iostream>

int main()
{
    int sum = 0, val = 1;
    while (val <= 10)
        sum += (val++);

    std::cout << "Sum of 1 to 10 inclusive is " << sum << std::endl;
    return 0;
}
/**
 * 可读性略有降低
 */
