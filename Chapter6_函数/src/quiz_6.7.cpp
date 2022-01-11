/**
 * 编写一个函数，当它第一次被调用时返回 0 ，以后每次被调用返回值加 1 。
 */

#include <iostream>

using std::cout;
using std::endl;

int count_calls(void)
{
    static int cnt = 0;
    return cnt++;
}

int main()
{
    for (int i = 0; i < 10; ++i)
        cout << count_calls() << endl;

    return 0;
}
