/**
 * 编写一个与用户交互的函数，要求用户输入一个数字，计算生成该数字的阶乘。
 * 在 main 函数中调用该函数。
 */

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void fact(void)
{
    unsigned int result = 1, n, temp;

    cout << "Enter a number: ";
    cin >> n;

    temp = n;
    while (temp > 1)
    {
        result *= temp--;
    }

    cout << n << "! is " << result << endl;
}

int main()
{
    fact();

    return 0;
}
