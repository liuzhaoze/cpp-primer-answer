/**
 * 重新编写 10.3.2 节的 biggies 函数，使用函数对象类替换其中的 lambda 表达式。
 */

#include <algorithm>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

class ShorterString
{
  public:
    bool operator()(const std::string &s1, const std::string &s2) const
    {
        return s1.size() < s2.size();
    }
};

class SizeComp
{
  private:
    std::size_t sz;

  public:
    SizeComp(std::size_t n) : sz(n)
    {
    }

    bool operator()(const std::string &s) const
    {
        return s.size() >= sz;
    }
};

std::string make_plural(std::size_t ctr, const std::string &word, const std::string ending)
{
    return (ctr > 1) ? word + ending : word;
}

void elimDups(std::vector<std::string> &words)
{
    std::sort(words.begin(), words.end()); // 按字典排序
    auto end_unique = std::unique(words.begin(), words.end());
    words.erase(end_unique, words.end()); // 删除重复的单词
}

void biggies(std::vector<std::string> &words, std::string::size_type sz)
{
    elimDups(words);                                               // 按字典排序，删除重复的单词
    std::stable_sort(words.begin(), words.end(), ShorterString()); // 按长度排序，长度相等的维持字典排序
    auto wc = std::find_if(words.begin(), words.end(), SizeComp(sz)); // 找到第一个长度大于等于 sz 的元素的迭代器

    auto count = words.end() - wc; // 计算长度大于等于 sz 的单词的总数目
    std::cout << count << " " << make_plural(count, "word", "s") << " of length " << sz << " or longer." << std::endl;

    // 打印长度大于等于 sz 的单词
    std::ostream_iterator<std::string> out(std::cout, " ");
    std::copy(wc, words.end(), out);
    std::cout << std::endl;
}

int main()
{
    std::ifstream ifstrm("../data/accum");
    std::vector<std::string> words;
    std::string s;

    while (ifstrm >> s)
    {
        words.push_back(s);
    }

    biggies(words, 5);

    return 0;
}
