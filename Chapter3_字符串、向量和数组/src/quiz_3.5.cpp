/**
 * 编写一段程序从标准输入中读入多个字符串并将它们连接在一起，
 * 输出连接成的大字符串。
 * 然后修改上述程序，用空格把输入的多个字符串分割开来。
 */

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string input, result1, result2;

    while (cin >> input) {
        result1 += input;
        result2 += (input + " ");
    }

    cout << result1 << endl;
    cout << string(60, '-') << endl;
    cout << result2 << endl;

    return 0;
}
