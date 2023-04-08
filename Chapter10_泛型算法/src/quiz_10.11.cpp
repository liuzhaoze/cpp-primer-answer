/**
 * 编写程序，使用 stable_sort 和 isShorter 将传递给你的 elimDups 版本的 vector 排序。
 * 打印 vector 的内容，验证你的程序的正确性。
 */

#include "../../lib/print_container.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

bool isShorter(const std::string &s1, const std::string &s2)
{
    return s1.size() < s2.size();
}

void elimDups(std::vector<std::string> &words)
{
    std::sort(words.begin(), words.end()); // 将 words 按字典顺序排序
    auto end_unique = std::unique(
        words.begin(),
        words.end()); // 将 words 中不重复的单词放在容器前面，返回指向最后一个不重复元素之后的位置的迭代器（end_unique
                      // 及其之后的元素仍然存在，但是不知道具体的值是什么）
    words.erase(end_unique, words.end()); // 删除多余的元素
}

int main()
{
    std::ifstream ifstrm("../data/count-size");
    std::vector<std::string> svec;
    std::string s;

    while (ifstrm >> s)
    {
        svec.push_back(s);
    }

    elimDups(svec);
    print_container(std::cout, svec.cbegin(), svec.cend()) << std::endl;

    std::stable_sort(svec.begin(), svec.end(), isShorter);
    print_container(std::cout, svec.cbegin(), svec.cend()) << std::endl;

    return 0;
}
