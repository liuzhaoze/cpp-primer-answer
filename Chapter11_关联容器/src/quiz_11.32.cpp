/**
 * 使用上一题定义的 multimap 编写一个程序，按字典顺序打印作者列表和他们的作品。
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>

int main()
{
    std::multimap<std::string, std::string> m = {{"D", "dragonfruit"}, {"A", "apple"},  {"B", "blueberry"},
                                                 {"C", "cherry"},      {"B", "banana"}, {"B", "blackberry"}};
    std::cout << "Before:" << std::endl;
    std::for_each(m.cbegin(), m.cend(), [](auto &i) { std::cout << "\t" << i.first << " " << i.second << std::endl; });

    // 使用 multiset 对作品进行排序
    std::map<std::string, std::multiset<std::string>> ordered_m;
    for (auto &each : m)
    {
        ordered_m[each.first].insert(each.second);
    }

    std::cout << "After:" << std::endl;
    for (auto &each : ordered_m)
    {
        for (auto &book : each.second)
        {
            std::cout << "\t" << each.first << " " << book << std::endl;
        }
    }

    return 0;
}
