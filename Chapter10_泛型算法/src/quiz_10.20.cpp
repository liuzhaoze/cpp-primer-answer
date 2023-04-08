/**
 * 标准库定义了一个名为 count_if 的算法。
 * 类似 find_if ，此函数接受一对迭代器，表示一个输入范围，还接受一个谓词，会对输入范围中每个元素执行。
 * count_if 返回一个计数值，表示谓词有多少次为真。
 * 使用 count_if 重写我们程序中统计有多少单词长度超过 6 的部分。
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

void biggies(std::vector<std::string> &words, std::vector<std::string>::size_type sz)
{
    elimDups(words); // 按字典排序，删除重复的单词
    std::stable_sort(words.begin(), words.end(), [](const std::string &a, const std::string &b) {
        return a.size() < b.size();
    }); // 按长度排序，长度相等的维持字典排序

    auto pivot = std::stable_partition(words.begin(), words.end(), [sz](const std::string &a) {
        return a.size() >= sz;
    }); // 将长度大于等于 sz 的元素分到容器前面

    auto count = std::count_if(words.begin(), words.end(), [sz](const std::string &s) {
        return s.size() >= sz;
    }); // 计算长度大于等于 sz 的单词的总数目
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

    biggies(words, 7);

    return 0;
}
