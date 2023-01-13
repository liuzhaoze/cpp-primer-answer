/**
 * 如何从一个 list<int> 初始化一个 vector<double> ？
 * 从一个 vector<int> 又该如何创建？
 * 编写代码验证你的答案。
 */

#include <iostream>
#include <list>
#include <ostream>
#include <vector>

template <typename T> std::ostream &print_container(std::ostream &ostrm, T begin, T end)
{
    while (begin != end)
    {
        ostrm << *begin << " ";
        ++begin;
    }

    return ostrm;
}

int main()
{
    std::list<int> ilst = {0, 1, 2, 3, 4};
    std::vector<int> ivec = {5, 6, 7, 8, 9};

    std::vector<double> dvec1(ilst.begin(), ilst.end());
    print_container(std::cout, dvec1.cbegin(), dvec1.cend()) << std::endl;

    std::vector<double> dvec2(ivec.begin(), ivec.end());
    print_container(std::cout, dvec2.cbegin(), dvec2.cend()) << std::endl;

    return 0;
}
