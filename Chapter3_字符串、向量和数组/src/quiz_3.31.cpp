/**
 * 编写一段程序，定义一个含有 10 个 int 的数组，
 * 令每个元素的值就是其下标的值。
 */

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int ia[10];

    for (size_t ix = 0; ix != 10; ++ix) {
        ia[ix] = ix;
    }

    for (auto i : ia) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
