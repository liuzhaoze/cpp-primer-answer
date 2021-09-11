/**
 * 编写一段程序，将含有整型元素的 vector 对象拷贝给一个整型数组。
 */

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> ivec = {1, 2, 3, 4, 5};
    int ia[5];

    for (decltype(ivec.size()) i = 0; i != ivec.size(); ++i) {
        ia[i] = ivec[i];
    }

    for (auto i : ia) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
