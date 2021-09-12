/**
 * 编写一段程序，使用条件运算符从 vector<int> 中找到哪些元素的值是奇数，
 * 然后将这些奇数值翻倍。
 */

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> ivec = {45, 65, 99, 100, 34, 67, 95, 76, 88, 75, 83, 92, 76, 93};

    for (auto i : ivec) {
        cout << i << " ";
    }
    cout << endl;

    for (auto &i : ivec) {
        i = ((i % 2) ? (i * 2) : i);
    }

    for (auto i : ivec) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
