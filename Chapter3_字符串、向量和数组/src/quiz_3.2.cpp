/**
 * 编写一段程序从标准输入中一次读入一行，
 * 然后修改该程序使其一次读入一个词。
 */

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    std::string str;

    // while (std::getline(cin, str))  // 一次读入一整行
    while (cin >> str)  // 一次读入一个词
        cout << str << endl;

    return 0;
}
