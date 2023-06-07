/**
 * 定义一个函数模板，统计一个给定值在一个 vector 中出现的次数。
 * 测试你的函数，分别传递给它一个 double 的 vector ，一个 int 的 vector 以及一个 string 的 vector 。
 */

#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

template <typename T> std::size_t count(const std::vector<T> &vec, T value)
{
    std::size_t cnt = 0;

    for (const auto &elem : vec)
    {
        if (elem == value)
        {
            ++cnt;
        }
    }

    return cnt;
}

int main()
{
    std::vector<double> vd = {1.1, 1.1, 2.3, 4};
    std::cout << count(vd, 1.1) << std::endl;

    std::vector<int> vi = {1, 1, 4, 5, 1, 4};
    std::cout << count(vi, 1) << std::endl;

    std::vector<std::string> vs = {"alan", "alan", "alan", "alan", "moophy"};
    std::cout << count(vs, std::string("alan")) << std::endl;

    return 0;
}
