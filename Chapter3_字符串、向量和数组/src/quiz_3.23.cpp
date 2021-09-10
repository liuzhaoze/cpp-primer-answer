/**
 * 编写一段程序，创建一个含有 10 个整数的 vector 对象，
 * 然后使用迭代器将所有元素的值都变成原来的两倍。
 * 输出 vector 对象的内容，检验程序是否正确。
 */

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> ivec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (auto it = ivec.begin(); it != ivec.end(); ++it) {
        cout << *it << " ";
        *it *= 2;
    }
    cout << endl;

    for (auto it = ivec.cbegin(); it != ivec.cend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
