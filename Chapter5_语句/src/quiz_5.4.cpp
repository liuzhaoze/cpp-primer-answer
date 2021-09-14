/**
 * 说明下列例子的含义，如果存在问题，试着修改它。
 */

#include <string>

using std::string;

bool find(string word);

int main()
{
    // (a)
    string s;

    while (string::iterator iter != s.end()) {
        /* ... */
    }
    // 变量 iter 未初始化
    string::iterator iter = s.begin();
    while (iter != s.end()) {
        /* ... */
    }


    // (b)
    string word;
    while (bool status = find(word)) {
        /* ... */
    }
        if (!status) {
            /* ... */
        }
    // status 超出块作用域
    bool status;
    while (bool status = find(word)) {
        /* ... */
    }
    if (!status) {
        /* ... */
    }

    return 0;
}
