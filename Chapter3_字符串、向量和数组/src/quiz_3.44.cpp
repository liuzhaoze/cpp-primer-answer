/**
 * 改写上一个练习中的程序，使用类型别名来代替循环控制变量的类型。
 */

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using int_array = int[4];

int main()
{
    int ia[3][4] = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11}};

    // 版本 1
    for (int_array &row : ia) {
        for (int col : row) {
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
    for (int_array *row = ia; row != ia + 3; ++row) {
        for (int *col = *row; col != *row + 4; ++col) {
            cout << *col << " ";
        }
        cout << endl;
    }

    return 0;
}
