/**
 * 下面的程序是何含义，程序的输出结果是什么？
 */

// 程序逐个输出字符数组中的元素，但很有可能越界，直到遇到空字符为止

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    const char ca[] = {'h', 'e', 'l', 'l', 'o'};
    const char *cp = ca;

    while (*cp) {
        cout << *cp << endl;
        ++cp;
    }

    return 0;
}
