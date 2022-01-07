/**
 * 编写一段程序，使用 do while 循环重复地执行下述任务：
 * 首先提示用户输入两个 string 对象，然后挑出较短的那个并输出他。
 */

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string s1, s2, res;

    do {
        cout << "Please input 2 strings:" << endl;
        cin >> s1 >> s2;
        cout << ((s1.length() < s2.length()) ? s1 : s2) << endl;

        cout << "Enter more? [y/n]" << endl;
        cin >> res;
    } while (!res.empty() && tolower(res[0]) == 'y');

    return 0;
}
