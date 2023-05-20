/**
 * 编写一个类令其检查某个给定的 string 对象的长度是否与一个阈值相等。
 * 使用该对象编写程序，统计并报告在输入的文件中长度为 1 的单词有多少个、长度为 2 的单词有多少个、……、
 * 长度为 10 的单词又有多少个。
 */

#include "../../lib/strip.hpp"
#include <algorithm>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

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
    std::vector<IsInRange> predicates;
    std::map<std::size_t, std::size_t> count;

    for (std::size_t i = 1; i <= 10; ++i)
    {
        predicates.push_back(IsInRange(i, i));
        count[i] = 0;
    }

    std::ifstream in_file("../data/storyDataFile");
    std::string word;
    while (in_file >> word)
    {
        word = strip(word);

        for (auto &is_in_range : predicates)
        {
            if (is_in_range(word))
            {
                ++count[is_in_range.limit().second]; // 此处上下限相等，用哪个都行
            }
        }
    }

    for (const auto &each : count)
    {
        std::cout << "There " << ((each.second > 1) ? "are " : "is ")
                  << ((each.second == 0) ? "no" : std::to_string(each.second))
                  << ((each.second > 1) ? " words" : " word") << " with a length of " << each.first << std::endl;
    }

    return 0;
}
