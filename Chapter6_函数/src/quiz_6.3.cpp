/**
 * 编写你自己的 fact 函数，上机检查是否正确。
 */

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

unsigned int fact(unsigned int n)
{
    unsigned int result = 1;

    while (n > 1)
    {
        result *= n--;
    }

    return result;
}

int main()
{
    unsigned int val;

    cout << "Enter a number: ";
    cin >> val;
    cout << val << "! is " << fact(val) << endl;

    return 0;
}
