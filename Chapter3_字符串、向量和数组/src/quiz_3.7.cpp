/**
 * 就上一题完成的程序而言，如果将循环控制变量的类型设为 char 将发生什么？
 * 先估计一下结果，然后实际编程进行验证。
 */

#include <iostream>
#include <string>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string str;
    std::getline(cin, str);
    cout << str << endl;

    // c 不是引用， str 中的字符将不会改变
    for (char c : str) {
        if (!std::isspace(c)) {
            c = 'X';
        }
    }
    cout << str << endl;

    return 0;
}
