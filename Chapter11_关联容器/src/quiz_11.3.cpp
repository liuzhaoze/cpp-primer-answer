/**
 * 编写你自己的单词计数程序。
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
        ++word_count[word];
    }

    for (const auto &w : word_count)
    {
        std::cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times." : " time.") << std::endl;
    }

    return 0;
}
