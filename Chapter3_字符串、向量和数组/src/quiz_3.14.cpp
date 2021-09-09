/**
 * 编写一段程序，用 cin 读入一组整数并把它们存入一个 vector 对象。
 */

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> ivec;
    int num;

    while (cin >> num) {
        ivec.push_back(num);
    }

    for (auto i : ivec) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
