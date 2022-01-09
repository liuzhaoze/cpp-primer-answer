/**
 * 修改你的程序，使得当第二个数是 0 时抛出异常。
 * 先不要设定 catch 子句，运行程序并真的为除数输入 0 ，看看会发生什么？
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

    if (b == 0)
        throw std::runtime_error("Divided by 0.");
    else
        cout << a << " divided by " << b << " equals to " << a / b << endl;

    return 0;
}
