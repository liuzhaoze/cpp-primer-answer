/**
 * 定义一个 map ，将单词与一个行号的 list 关联，list 中保存的是单词所出现的行号。
 */

#include "../../lib/strip.hpp"
#include <algorithm>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <sstream>
#include <string>

int main()
{
    std::ifstream ifstrm("../data/word_count");
    std::map<std::string, std::list<int>> word_line_number;
    std::string line;
    std::size_t line_number = 0;

    while (std::getline(ifstrm, line))
    {
        ++line_number;
        std::istringstream line_strm(line);
        std::string word;

        while (line_strm >> word)
        {
            word_line_number[strip(word)].push_back(line_number);
        }
    }

    std::ostream_iterator<int> out_iter(std::cout, " ");
    for (const auto &each : word_line_number)
    {
        std::cout << each.first << ": ";
        std::copy(each.second.cbegin(), each.second.cend(), out_iter);
        std::cout << std::endl;
    }

    return 0;
}
