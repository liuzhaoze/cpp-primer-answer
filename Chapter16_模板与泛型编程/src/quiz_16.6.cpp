/**
 * 你认为接受一个数组实参的标准库函数 begin 和 and 是如何工作的？
 * 定义你自己版本的 begin 和 end 。
 */

#include <iostream>
#include <string>

namespace quiz
{
template <typename T, unsigned size> T *begin(T (&arr)[size])
{
    return arr;
}

template <typename T, unsigned size> T *end(T (&arr)[size])
{
    return arr + size;
}
} // namespace quiz

int main()
{
    std::string s[] = {"a", "bb", "ccc", "dddd"};

    std::cout << *(quiz::begin(s) + 1) << std::endl;
    std::cout << *(quiz::end(s) - 1) << std::endl;

    return 0;
}
