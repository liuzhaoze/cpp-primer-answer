/**
 * 编写一个递归函数，输出 vector 对象的内容。
 */

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using Iter = std::vector<int>::const_iterator;

void print_vector(Iter begin, Iter end)
{
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
