/**
 * 为上一题中的模板编写特例化版本来处理 vector<const char *> 。
 * 编写程序使用这个特例化版本。
 */

#include <cstddef>
#include <cstring>
#include <iostream>
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

// 特例化：当 vector 中存放字符串常量指针时，比较字符串相等需要特殊处理
template <> std::size_t count(const std::vector<const char *> &vec, const char *value)
{
    std::size_t cnt = 0;

    for (const auto &elem : vec)
    {
        if (std::strcmp(elem, value) == 0)
        {
            ++cnt;
        }
    }

    return cnt;
}

int main()
{
    std::vector<const char *> vcc = {"alan", "alan", "alan", "alan", "moophy"};
    std::cout << count(vcc, "alan") << std::endl;
}
