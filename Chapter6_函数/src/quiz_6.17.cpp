/**
 * 编写一个函数，判断 string 对象中是否含有大写字母。
 * 编写另一个函数，把 string 对象全都改成小写形式。
 * 在这两个函数中你使用的形参类型相同吗？为什么？
 */

#include <iostream>
#include <string>
#include <cctype>

using std::cout;
using std::endl;
using std::string;

bool have_upper(const string &s)
{
    for (auto c : s)
        if (isupper(c))
            return true;
    
    return false;
}

void to_lower_string(string &s)
{
    for (auto &c : s)
        c = tolower(c);
}

int main()
{
    // string str = "abcdefghijklmnop";
    string str = "ABCdefGHIjkLMNop";

    cout << str << endl;

    if (have_upper(str))
    {
        cout << "Have upper letter." << endl;
        cout << "Convert to lower letters." << endl;
        to_lower_string(str);
        cout << str << endl;
    }
    else
    {
        cout << "Doesn't have upper letter." << endl;
    }

    return 0;
}
