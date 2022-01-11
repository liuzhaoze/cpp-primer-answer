/**
 * 编写一个函数输出其实参的绝对值。
 */

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

double my_abs(double n)
{
    if (n < 0.0)
        return -n;
    else
        return n;
}

int main()
{
    double val;

    cout << "Enter a number: ";
    cin >> val;
    cout << "The absolute value of " << val << " is " << my_abs(val) << endl;

    return 0;
}
