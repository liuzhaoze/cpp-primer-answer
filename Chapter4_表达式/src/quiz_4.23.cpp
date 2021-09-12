/**
 * 因为运算符的优先级问题，下面这条表达式无法通过编译。
 * 指出它的问题在哪里？应该如何修改？
 */

#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

int main()
{
    string s = "word";
    // string p1 = s + s[s.size() - 1] == 's' ? "" : "s";
    string p1 = s + ((s[s.size() - 1] == 's') ? "" : "s");

    cout << s << endl;
    cout << p1 << endl;

    return 0;
}
