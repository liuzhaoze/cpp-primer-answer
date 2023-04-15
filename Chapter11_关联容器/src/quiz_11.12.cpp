/**
 * 编写程序，读入 string 和 int 的序列，将每个 string 和 int 存入一个 pair 中，pair 保存在一个 vector 中。
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
        vec.push_back({s, i});
        // vec.push_back(std::make_pair(s, i));
        // vec.push_back(pair_t(s, i));
        // vec.emplace_back(s, i);
    }

    std::for_each(vec.cbegin(), vec.cend(),
                  [](const pair_t &each) { std::cout << each.first << " " << each.second << std::endl; });

    return 0;
}
