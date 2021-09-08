/**
 * 下面的范围 for 语句合法吗？
 * 如果合法， c 的类型是什么？
 */

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main()
{
    const string s = "Keep out!";

    for (auto &c : s) {
        cout << c << endl;
    }
    // 合法， c 的类型是 const char &

    return 0;
}
