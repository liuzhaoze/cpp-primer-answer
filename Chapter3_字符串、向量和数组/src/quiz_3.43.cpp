/**
 * 编写 3 个不同版本的程序，令其均能输出 ia 的元素。
 * 版本 1 使用范围 for 语句管理迭代过程；
 * 版本 2 和版本 3 都使用普通的 for 语句，
 * 其中版本 2 要求用下标运算符，版本 3 要求用指针。
 * 此外，在所有 3 个版本的程序中都要直接写出数据类型，
 * 而不能使用类型别名、 auto 关键字或 decltype 关键字。
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
    for (int (&row)[4] : ia) {
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
    for (int(*row)[4] = ia; row != ia + 3; ++row) {
        for (int *col = *row; col != *row + 4; ++col) {
            cout << *col << " ";
        }
        cout << endl;
    }

    return 0;
}
