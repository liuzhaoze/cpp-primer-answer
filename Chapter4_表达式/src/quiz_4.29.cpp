/**
 * 推断下面代码的输出结果并说明理由。
 * 实际运行这段程序，结果和你想象的一样吗？
 * 如果不一样，为什么？
 */

#include <iostream>

using std::cout;
using std::endl;

int main()
{
    int x[10];
    int *p = x;

    cout << sizeof(x) / sizeof(*x) << endl;  // 输出数组元素个数： 10
    cout << sizeof(p) / sizeof(*p) << endl;  // 指针所占空间 8 除以 int 所占空间 4 ： 2

    return 0;
}
