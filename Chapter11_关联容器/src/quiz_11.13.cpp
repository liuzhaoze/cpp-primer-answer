/**
 * 在上一题的程序中，至少有 3 种创建 pair 的方法。
 * 编写此程序的 3 个版本，分别采用不同的方法创建 pair 。
 * 解释你认为哪种形式最易于编写和理解，为什么？
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

int main()
{
    using pair_t = std::pair<std::string, int>;
    std::vector<pair_t> vec;
    std::string s;
    int i;

    while (std::cin >> s >> i)
    {
        // 总计 4 种等价写法
        vec.push_back({s, i});               // 使用大括号列表构造 pair
        vec.push_back(std::make_pair(s, i)); // 使用 make_pair 构造 pair
        vec.push_back(pair_t(s, i));         // 使用显式构造 pair
        vec.emplace_back(s, i);              // 使用 emplace 构造 pair
    }

    std::for_each(vec.cbegin(), vec.cend(),
                  [](const pair_t &each) { std::cout << each.first << " " << each.second << std::endl; });

    return 0;
}
