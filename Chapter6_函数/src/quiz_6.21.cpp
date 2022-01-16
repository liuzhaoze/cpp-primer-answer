/**
 * 编写一个函数，令其接受两个参数：一个是 int 型的数，另一个是 int 指针。
 * 函数比较 int 的值和指针所指的值，返回较大的那个。
 * 在该函数中指针的类型应该是什么？
 */

#include <iostream>

using std::cout;
using std::endl;


int larger_one(const int a, const int *b)
{
    if (a > *b)
        return a;
    else
        return *b;
}

int main()
{
    int val1 = 15, val2 = 10;

    cout << "The larger one is " << larger_one(val1, &val2) << endl;

    return 0;
}
