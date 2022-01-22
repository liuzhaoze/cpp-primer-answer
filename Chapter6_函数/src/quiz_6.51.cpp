/**
 * 编写函数 f 的 4 个版本，令其各输出一条可以区分的消息。
 * 验证上一个练习的答案。
 */

#include <iostream>
#include <string>

using std::cout;
using std::endl;

void f()
{
    cout << "The 1st function." << endl;
}

void f(int a)
{
    cout << "The 2nd function." << endl;
    cout << a << endl;
}

void f(int a, int b)
{
    cout << "The 3rd function." << endl;
    cout << a << " " << b << endl;
}

void f(double a, double b = 3.14)
{
    cout << "The 4th function." << endl;
    cout << a << " " << b << endl;
}

int main(int argc, char** argv)
{
    cout << std::string(40, '-') << endl;
    // f(2.56, 42);
    cout << std::string(40, '-') << endl;
    f(42);
    cout << std::string(40, '-') << endl;
    f(42, 0);
    cout << std::string(40, '-') << endl;
    f(2.56, 3.14);
    cout << std::string(40, '-') << endl;

    return 0;
}
