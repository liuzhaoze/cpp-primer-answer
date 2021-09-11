/**
 * 将上一题刚刚创建的数组拷贝给另外一个数组。
 * 利用 vector 重写程序，实现类似的功能。
 */

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    int ia[10], ia2[10];

    for (size_t ix = 0; ix != 10; ++ix) {
        ia[ix] = ix;
    }

    // 数组拷贝
    for (size_t ix = 0; ix != 10; ++ix) {
        ia2[ix] = ia[ix];
    }

    for (auto i : ia2)
    {
        cout << i << " ";
    }
    cout << endl;

    // 利用 vector 重写程序
    vector<int> iv, iv2;

    for (int i = 0; i != 10; ++i) {
        iv.push_back(i);
    }

    iv2 = iv;

    for (auto i : iv2) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
