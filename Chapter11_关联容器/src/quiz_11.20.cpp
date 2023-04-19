/**
 * 重写 11.1 节练习的单词计数程序，使用 insert 代替下标操作。
 * 你认为哪个程序更容易编写和阅读？解释原因。
 */

#include <cstddef>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

int main()
{
    std::ifstream ifstrm("../data/word_count");
    std::map<std::string, std::size_t> word_count;
    std::string word;

    while (ifstrm >> word)
    {
        // ++word_count[word];
        auto ret = word_count.insert({word, 1});

        if (!ret.second)
        {
            ++ret.first->second;
        }
        // 下标操作比 insert 更易读
    }

    for (const auto &w : word_count)
    {
        std::cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times." : " time.") << std::endl;
    }

    return 0;
}
