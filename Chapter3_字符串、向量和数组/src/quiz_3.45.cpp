/**
 * 再一次改写程序，这次使用 auto 关键字。
 */

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int ia[3][4] = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11}};

    // 版本 1
    for (auto &row : ia) {
        for (auto col : row) {
            cout << col << " ";
        }
        cout << endl;
    }

    // 版本 2
    for (size_t row = 0; row != 3; ++row) {
        for (size_t col = 0; col != 4; ++col) {
            cout << ia[row][col] << " ";
        }
        cout << endl;
    }

    // 版本 3
    for (auto row = ia; row != ia + 3; ++row) {
        for (auto col = *row; col != *row + 4; ++col) {
            cout << *col << " ";
        }
        cout << endl;
    }

    return 0;
}
