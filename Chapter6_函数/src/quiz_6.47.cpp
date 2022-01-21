/**
 * 改写使用递归输出 vector 内容的程序，使其有条件地输出与执行过程有关的信息。
 * 例如，每次调用时输出 vector 对象的大小。
 * 分别在打开和关闭调试器的情况下编译并执行这个程序。
 */
#define NDEBUG

#include <iostream>
#include <vector>
#include <cassert>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;
using Iter = std::vector<int>::const_iterator;

void print_vector(Iter begin, Iter end)
{
#ifndef NDEBUG
    cerr << __func__ << ": vector size is " << end - begin << endl;
#endif

    if (begin != end)
    {
        cout << *begin << endl;
        print_vector(++begin, end);
    }
}

int main(int argc, char *argv[])
{
    vector<int> vec = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    print_vector(vec.cbegin(), vec.cend());

    return 0;
}
