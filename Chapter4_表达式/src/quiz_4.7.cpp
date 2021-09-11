/**
 * 溢出是何含义？
 * 写出三条将导致溢出的表达式。
 */

#include <iostream>

using std::cout;
using std::endl;

int main()
{
    int i = 0x7fffffff;
    unsigned ui1 = 0xffffffff;
    unsigned ui2 = 0;

    cout << i << endl;
    cout << i + 1 << endl << endl;

    cout << ui1 << endl;
    cout << ui1 + 1 << endl << endl;

    cout << ui2 << endl;
    cout << ui2 - 1 << endl << endl;

    return 0;
}
