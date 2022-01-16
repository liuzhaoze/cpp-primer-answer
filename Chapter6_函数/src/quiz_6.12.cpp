/**
 * 改写练习 6.10 的程序，使用引用而非指针交换两个整数的值。
 * 你觉得哪种方法更易于使用呢？为什么？
 * 引用更易于使用。因为其不需要对指针解引用。
 */

#include <iostream>

using std::cout;
using std::endl;

void swap_two_int(int &p, int &q)
{
    int temp;

    temp = p;
    p = q;
    q = temp;

    return;
}

int main()
{
    int a = 5, b = 99;
    cout << "a = " << a << ", b = " << b << endl;

    swap_two_int(a, b);
    cout << "a = " << a << ", b = " << b << endl;

    return 0;
}
