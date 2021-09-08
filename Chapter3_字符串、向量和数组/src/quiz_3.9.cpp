/**
 * 下面的程序有何作用？它合法吗？如果不合法，为什么？
 */

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main()
{
    string s;
    cout << s[0] << endl;
    // 程序向输出字符串 s 的第一个字符。
    // 不合法， s 是空字符串，对空字符串索引会产生错误。

    return 0;
}
