/**
 * 编写一段程序，使用范围 for 语句将字符串内的所有字符用 X 代替。
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

    for (auto &c : str) {
        if (!std::isspace(c)) {
            c = 'X';
        }
    }
    cout << str << endl;

    return 0;
}
