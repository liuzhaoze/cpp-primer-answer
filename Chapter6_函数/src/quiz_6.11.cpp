/**
 * 编写并验证自己的 reset 函数，使其作用于引用类型的参数。
 */

#include <iostream>

using std::cout;
using std::endl;

void my_reset(int &i)
{
    i = 0;
    return;
}

int main()
{
    int n = 42;
    cout << "n = " << n << endl;

    my_reset(n);
    cout << "n (reset) = " << n << endl;

    return 0;
}
