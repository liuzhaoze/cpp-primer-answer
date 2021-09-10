/**
 * 修改之前那个输出 text 第一段的程序，首先把 text 的第一段全部改成大写形式，然后再输出它。
 */

#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    vector<string> text;
    string line;

    while (std::getline(cin, line)) {
        text.push_back(line);
    }

    for (auto it = text.begin(); it != text.end() && !it->empty(); ++it) {
        for (auto c = it->begin(); c != it->end(); ++c) {
            *c = std::toupper(*c);
        }
        cout << *it << endl;
    }

    return 0;
}
