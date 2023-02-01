/**
 * 编写程序，分别使用 at 、下标运算符、 front 和 begin 提取一个 vector 中的第一个元素。
 * 在一个空 vector 上测试你的程序。
 */

#include <iostream>
#include <ostream>
#include <vector>

std::ostream &test(std::vector<int> vec, std::ostream &ostrm)
{
    ostrm << "[" << vec.at(0) << "] ";
    ostrm << "[" << vec[0] << "] ";
    ostrm << "[" << vec.front() << "] ";
    ostrm << "[" << *vec.begin() << "] ";

    return ostrm;
}

int main()
{
    std::vector<int> ivec = {1, 2, 3, 4, 5};
    std::vector<int> empty_vec;

    test(ivec, std::cout) << std::endl;
    test(empty_vec, std::cout) << std::endl;

    return 0;
}
