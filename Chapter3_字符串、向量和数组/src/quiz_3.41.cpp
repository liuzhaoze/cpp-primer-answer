/**
 * 编写一段程序，用整型数组初始化一个 vector 对象。
 */

#include <iostream>
#include <vector>
#include <iterator>

using std::begin;
using std::cout;
using std::end;
using std::endl;
using std::vector;

int main()
{
    int ia[] = {1, 2, 3, 4, 5};
    vector<int> ivec(begin(ia), end(ia));

    for (auto i : ivec) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
