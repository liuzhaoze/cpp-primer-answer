/**
 * 编写一段程序，读入一个包含标点符号的字符串，
 * 将标点符号去除后输出字符串剩余的部分。
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

    string str_no_punct;
    for (auto c : str) {
        if (!std::ispunct(c)) {
            str_no_punct += c;
        }
    }
    cout << str_no_punct << endl;

    return 0;
}
