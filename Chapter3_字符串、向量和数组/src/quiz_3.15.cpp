/**
 * 编写一段程序，用 cin 读入一组整数并把它们存入一个 vector 对象。
 */

#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    vector<string> svec;
    string s;

    while (cin >> s) {
        svec.push_back(s);
    }

    for (auto i : svec) {
        cout << i << endl;
    }

    return 0;
}
