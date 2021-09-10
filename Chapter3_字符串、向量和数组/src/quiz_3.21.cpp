/**
 * 请使用迭代器重做 3.3.3 节的第一个练习。
 */

/**
 * 编写一段程序，把练习 3.13 中 vector 对象的容量和具体内容输出出来。
 * 检验你之前的回答是否正确。
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
    vector<int> v1;  // 包含 0 个元素
    vector<int> v2(10);  // 包含 10 个 0
    vector<int> v3(10, 42);  // 包含 10 个 42
    vector<int> v4{10};  // 包含 1 个 10
    vector<int> v5{10, 42};  // 包含 1 个 10 和 1 个 42
    vector<string> v6{10};  // 包含 10 个空字符串
    vector<string> v7{10, "hi"};  // 包含 10 个 "hi" 字符串

    cout << string(30, '-') << " v1 " << string(30, '-') << endl;
    cout << v1.size() << endl;
    for (auto it = v1.begin(); it != v1.end(); ++it)
        cout << *it << " ";
    cout << endl;

    cout << string(30, '-') << " v2 " << string(30, '-') << endl;
    cout << v2.size() << endl;
    for (auto it = v2.begin(); it != v2.end(); ++it)
        cout << *it << " ";
    cout << endl;
    
    cout << string(30, '-') << " v3 " << string(30, '-') << endl;
    cout << v3.size() << endl;
    for (auto it = v3.begin(); it != v3.end(); ++it)
        cout << *it << " ";
    cout << endl;

    cout << string(30, '-') << " v4 " << string(30, '-') << endl;
    cout << v4.size() << endl;
    for (auto it = v4.begin(); it != v4.end(); ++it)
        cout << *it << " ";
    cout << endl;

    cout << string(30, '-') << " v5 " << string(30, '-') << endl;
    cout << v5.size() << endl;
    for (auto it = v5.begin(); it != v5.end(); ++it)
        cout << *it << " ";
    cout << endl;

    cout << string(30, '-') << " v6 " << string(30, '-') << endl;
    cout << v6.size() << endl;
    for (auto it = v6.begin(); it != v6.end(); ++it)
        cout << *it << " ";
    cout << endl;

    cout << string(30, '-') << " v7 " << string(30, '-') << endl;
    cout << v7.size() << endl;
    for (auto it = v7.begin(); it != v7.end(); ++it)
        cout << *it << " ";
    cout << endl;

    return 0;
}
