/**
 * 编写一段程序读入两个字符串。比较其是否相等并输出结果。
 * 如果不相等，输出较大的那个字符串。
 * 改写上述程序，比较输入的两个字符串是否等长，如果不等长，输出长度较大的那个字符串。
 */

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string s1, s2;

    std::getline(cin, s1);
    std::getline(cin, s2);

    // 比较是否相等
    if (s1 == s2) {
        cout << "two strings are same." << endl;
    }
    else if (s1 > s2) {
        cout << s1 << endl;
    }
    else {
        cout << s2 << endl;
    }

    // 比较长度是否相等
    if (s1.size() == s2.size()) {
        cout << "two strings are the same length." << endl;
    }
    else if (s1.size() > s2.size()) {
        cout << s1 << endl;
    }
    else {
        cout << s2 << endl;
    }

    return 0;
}
