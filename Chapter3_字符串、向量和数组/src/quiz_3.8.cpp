/**
 * 分别用 while 循环和传统的 for 循环重写第一题的程序，你觉得哪种形式更好？为什么？
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

    string str1 = str, str2 = str;
    string::size_type i = 0;

    // while 循环
    while (i != str1.size()) {
        if (!std::isspace(str1[i])) {
            str1[i] = 'X';
        }
        ++i;
    }
    cout << str1 << endl;

    // 传统 for 循环
    for (i = 0; i != str2.size(); ++i) {
        if (!std::isspace(str2[i])) {
            str2[i] = 'X';
        }
    }
    cout << str2 << endl;

    return 0;
}
/**
 * 范围 for 语句更好，因为其不用检查下标的合法性。
 */
