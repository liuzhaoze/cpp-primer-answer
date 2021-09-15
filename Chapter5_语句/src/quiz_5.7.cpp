/**
 * 改正下列代码段中的错误。
 */

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int get_value(void);

int main()
{
    int ival1, ival2, minval, ival, occurs;

    // (a)
    if (ival1 != ival2)
        ival1 = ival2        // 错误：缺少 ;
    else ival1 = ival2 = 0;

    // (b)
    if (ival < minval)
        minval = ival;
        occurs = 1;     // 错误：应把两个语句放在语句块中

    // (c)
    if (int ival = get_value())
        cout << "ival = " << ival << endl;
    if (!ival)                 // 错误：超出了上一个 if 中 ival 的作用域
        cout << "ival = 0\n";

    // (d)
    if (ival = 0)            // 错误：该条件恒为假
        ival = get_value();

    return 0;
}
