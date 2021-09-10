/**
 * 3.3.3 节划分分数段的程序是使用下标运算符实现的，
 * 请利用迭代器改写该程序并实现完全相同的功能。
 */

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<unsigned> scores(11, 0);
    unsigned grade;

    auto beg = scores.begin();
    while (cin >> grade) {
        if (grade <= 100) {
            ++(*(beg + grade / 10));
        }
    }

    for (auto i : scores) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
