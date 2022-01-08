/**
 * 修改 quiz_5.20.cpp ，使其找到的重复单词必须以大写字母开头。
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
    string str, pre_str;
    bool duplicated = false;

    while (cin >> str && !str.empty())
    {
        if (str == pre_str && isupper(str[0]))
        {
            duplicated = true;
            break;
        }

        pre_str = str;
    }

    if (!duplicated)
        cout << "There is no duplicated word." << endl;
    else
        cout << "The duplicated word is \"" << pre_str << "\"." << endl;

    return 0;
}
