/**
 * 编写一个函数，使用指针形参交换两个整数的值。
 * 在代码中调用该函数并输出交换后的结果，以此验证函数的正确性。
 */

#include <iostream>

using std::cout;
using std::endl;

void swap_two_int(int *const p, int *const q)
{
    int temp;

    temp = *p;
    *p = *q;
    *q = temp;

    return;
}

int main()
{
    int a = 5, b = 99;
    cout << "a = " << a << ", b = " << b << endl;

    swap_two_int(&a, &b);
    cout << "a = " << a << ", b = " << b << endl;

    return 0;
}
