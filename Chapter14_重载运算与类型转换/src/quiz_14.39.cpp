/**
 * 修改上一题的程序令其报告长度在 1 至 9 之间的单词有多少个、长度在 10 以上的单词又有多少个。
 */

#include "../../lib/strip.hpp"
#include <algorithm>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <utility>

class IsInRange
{
  private:
    std::size_t upper;
    std::size_t lower;

  public:
    IsInRange(std::size_t l, std::size_t u) : lower(l), upper(u)
    {
    }

    std::pair<std::size_t, std::size_t> limit() const
    {
        return {lower, upper};
    }

    bool operator()(const std::string &s) const
    {
        return (s.size() >= lower) && (s.size() <= upper);
    }
};

int main()
{
    IsInRange iir(1, 9);
    std::map<std::string, std::size_t> count{{"1_to_9", 0}, {"above_10", 0}};
    std::ifstream in_file("../data/storyDataFile");
    std::string word;

    while (in_file >> word)
    {
        word = strip(word);

        if (!word.empty())
        {
            if (iir(word))
            {
                ++count["1_to_9"];
            }
            else
            {
                ++count["above_10"];
            }
        }
    }

    for (const auto &each : count)
    {
        std::cout << "There " << ((each.second > 1) ? "are " : "is ")
                  << ((each.second == 0) ? "no" : std::to_string(each.second))
                  << ((each.second > 1) ? " words" : " word") << " with a length: " << each.first << std::endl;
    }

    return 0;
}
