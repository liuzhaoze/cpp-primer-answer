/**
 * 编写一段程序，比较两个 string 对象。
 * 再编写一段程序，比较两个 C 风格字符串的内容。
 */

#include <iostream>
#include <string>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;
using std::strcmp;
using std::string;

int main()
{
    string s1 = "2Hello";
    string s2 = "1World";
    char ca1[] = "2Hello";
    char ca2[] = "1World";

    // 比较 string 对象
    if (s1 < s2) {
        cout << "s1 is smaller than s2." << endl;
    }
    else if (s1 > s2) {
        cout << "s1 is bigger than s2." << endl;
    }
    else {
        cout << "s1 is equal to s2." << endl;
    }

    // 比较 C 风格字符串
    if (strcmp(ca1, ca2) < 0) {
        cout << "ca1 is smaller than ca2." << endl;
    }
    else if (strcmp(ca1, ca2) > 0) {
        cout << "ca1 is bigger than ca2." << endl;
    }
    else {
        cout << "ca1 is equal to ca2." << endl;
    }

    return 0;
}
