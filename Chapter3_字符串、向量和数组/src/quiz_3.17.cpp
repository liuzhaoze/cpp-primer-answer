/**
 * 从 cin 读入一组词并把它们存入一个 vector 对象，
 * 然后设法把所有词都改写为大写形式。
 * 输出改变后的结果，每个词占一行。
 */

#include <iostream>
#include <string>
#include <vector>

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
        for (auto &c : s) {
            c = std::toupper(c);
        }
        svec.push_back(s);
    }

    for (auto word : svec) {
        cout << word << endl;
    }

    return 0;
}
