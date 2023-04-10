/**
 * 一个 vector 中保存 1 到 9 ，将其拷贝到三个其他容器中。
 * 分别使用 inserter 、back_inserter 和 front_inserter 将元素添加到三个容器中。
 * 对每种 inserter ，估计输出序列是怎样的，运行程序验证你的估计是否正确。
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

int main()
{
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::list<int> vec1, vec2, vec3;

    auto ins = std::inserter(vec1, vec1.begin());
    auto b_ins = std::back_inserter(vec2);
    auto f_ins = std::front_inserter(vec3);

    for (const auto &i : vec)
    {
        ins = i;
        b_ins = i;
        f_ins = i;
    }

    std::for_each(vec1.cbegin(), vec1.cend(), [](const int &i) { std::cout << i << " "; });
    std::cout << std::endl; // 1 2 3 4 5 6 7 8 9

    std::for_each(vec2.cbegin(), vec2.cend(), [](const int &i) { std::cout << i << " "; });
    std::cout << std::endl; // 1 2 3 4 5 6 7 8 9

    std::for_each(vec3.cbegin(), vec3.cend(), [](const int &i) { std::cout << i << " "; });
    std::cout << std::endl; // 9 8 7 6 5 4 3 2 1

    return 0;
}
