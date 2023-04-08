/**
 * 用 stable_partition 重写前一题的程序，与 stable_sort 类似，在划分后的序列中维持原有元素的顺序。
 */

#include <algorithm>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

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
    elimDups(words); // 按字典排序，删除重复的单词
    std::stable_sort(words.begin(), words.end(), [](const std::string &a, const std::string &b) {
        return a.size() < b.size();
    }); // 按长度排序，长度相等的维持字典排序

    auto pivot = std::stable_partition(words.begin(), words.end(), [sz](const std::string &a) {
        return a.size() >= sz;
    }); // 将长度大于等于 sz 的元素分到容器前面

    auto count = pivot - words.begin(); // 计算长度大于等于 sz 的单词的总数目
    std::cout << count << " " << make_plural(count, "word", "s") << " of length " << sz << " or longer." << std::endl;

    // 打印长度大于等于 sz 的单词
    std::for_each(words.begin(), pivot, [](const std::string &s) { std::cout << s << " "; });
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
