/**
 * 编写程序，定义一个作者及其作品的 multimap 。
 * 使用 find 在 multimap 中查找一个元素并用 erase 删除它。
 * 确保你的程序在元素不在 map 中时也能正常运行。
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <string>

int main()
{
    std::multimap<std::string, std::string> m = {{"A", "apple"}, {"B", "blueberry"}, {"C", "cherry"}, {"B", "banana"}};
    std::string author_to_delete = "B";
    std::string book_to_delete = "banana";

    std::cout << "Before:" << std::endl;
    std::for_each(m.cbegin(), m.cend(), [](auto &i) { std::cout << "\t" << i.first << " " << i.second << std::endl; });

    auto iter = m.find(author_to_delete);
    auto count = m.count(author_to_delete);
    while (count)
    {
        if (iter->second == book_to_delete)
        {
            m.erase(iter);
            break;
        }
        ++iter;
        --count;
    }

    std::cout << "After:" << std::endl;
    std::for_each(m.cbegin(), m.cend(), [](auto &i) { std::cout << "\t" << i.first << " " << i.second << std::endl; });

    return 0;
}
