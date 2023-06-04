/**
 * 编写并测试你自己版本的 compare 函数。
 */

#include <iostream>
#include <vector>

template <typename T> int compare(const T &v1, const T &v2)
{
    if (v1 < v2)
    {
        return -1;
    }
    if (v2 < v1)
    {
        return 1;
    }
    return 0;
}

int main()
{
    std::cout << compare(1, 0) << std::endl;

    std::vector<int> vec1{1, 2, 3}, vec2{4, 5, 6};
    std::cout << compare(vec1, vec2) << std::endl;

    return 0;
}
