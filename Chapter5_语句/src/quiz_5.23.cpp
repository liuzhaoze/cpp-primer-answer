/**
 * 编写一段程序，从标准输入读取两个整数，输出第一个数除以第二个数的结果。
 */

#include <iostream>
#include <stdexcept>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    int a, b;

    cout << "Enter two numbers:" << endl;
    cin >> a >> b;
    cout << a << " divided by " << b << " equals to " << a / b << endl;

    return 0;
}
