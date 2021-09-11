/**
 * 编写一段程序，利用指针将数组中的元素置为 0 。
 */

#include <iostream>
#include <string>
#include <iterator>

using std::begin;
using std::cin;
using std::cout;
using std::end;
using std::endl;

int main()
{
    int ia[10];

    for (auto i : ia) {
        cout << i << endl;
    }
    cout << std::string(60, '-') << endl;

    // 元素置 0
    for (int *p = begin(ia); p != end(ia); ++p) {
        *p = 0;
    }

    for (auto i : ia) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
