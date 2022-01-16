/**
 * 编写一个函数，令其交换两个 int 指针。
 */

#include <iostream>

using std::cout;
using std::endl;

void swap_int_pointer(int *&a, int *&b)
{
    int *temp = a;
    a = b;
    b = temp;
}

int main()
{
    int ival1 = 10, ival2 = 20;
    int *p = &ival1, *q = &ival2;

    cout << "*p = " << *p << " ; *q = " << *q << endl;
    swap_int_pointer(p, q);
    cout << "*p = " << *p << " ; *q = " << *q << endl;

    return 0;
}
