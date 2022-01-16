/**
 * 编写一个函数，他的参数是 initializer_list<int> 类型的对象。
 * 函数的功能是计算列表中所有元素的和。
 */

#include <iostream>
#include <initializer_list>

using std::cout;
using std::endl;
using std::initializer_list;

int list_sum(initializer_list<int> lst)
{
    int result = 0;

    for (auto i : lst)
        result += i;

    return result;
}

int main(int argc, char *argv[])
{
    cout << list_sum({1, 2, 3, 4, 5}) << endl;

    return 0;
}
