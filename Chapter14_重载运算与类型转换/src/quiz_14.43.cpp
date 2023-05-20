/**
 * 使用标准库函数对象判断一个给定的 int 值是否能被 int 容器中的所有元素整除。
 */

#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> factors = {2, 3, 5, 7, 11};
    int number;
    std::cin >> number;

    // 在 number 模除以所有 factor 都是 0 时为 true
    bool is_divisible =
        std::none_of(factors.cbegin(), factors.cend(), std::bind(std::modulus<int>(), number, std::placeholders::_1));

    std::cout << (is_divisible ? "Yes" : "No") << std::endl;

    return 0;
}
