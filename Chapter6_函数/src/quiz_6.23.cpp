/**
 * 参考本节介绍的几个 print 函数，根据理解编写你自己的版本。
 * 一次调用每个函数使其输入下面定义的 i 和 j 。
 */

#include <iostream>

using std::begin;
using std::cout;
using std::end;
using std::endl;

void print(const int *pi)
{
    if (pi)
        cout << *pi << endl;
}

void print(const char *p)
{
    if (p)
        while (*p)
            cout << *p++;
    cout << endl;
}

void print(const int *beg, const int *end)
{
    while (beg != end)
        cout << *beg++ << endl;
}

void print(const int ia[], size_t size)
{
    for (size_t i = 0; i != size; ++i)
    {
        cout << ia[i] << endl;
    }
}

void print(int (&arr)[2])
{
    for (auto i : arr)
        cout << i << endl;
}

int main()
{
    int i = 0, j[2] = {0, 1};
    char ch[5] = "abcd";

    print(ch);
    print(begin(j), end(j));
    print(&i);
    print(j, end(j) - begin(j));
    print(j);

    return 0;
}
