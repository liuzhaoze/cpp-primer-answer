/**
 * 实现你自己的 elimDups 。
 * 测试你的程序，分别在读取输入后、调用 unique 后以及调用 erase 后打印 vector 的内容。
 */

#include "../../lib/print_container.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

void elimDups(std::vector<std::string> &words)
{
    // 读取输入后
    print_container(std::cout, words.cbegin(), words.cend()) << std::endl;

    std::sort(words.begin(), words.end()); // 将 words 按字典顺序排序
    print_container(std::cout, words.cbegin(), words.cend()) << std::endl;

    auto end_unique = std::unique(
        words.begin(),
        words.end()); // 将 words 中不重复的单词放在容器前面，返回指向最后一个不重复元素之后的位置的迭代器（end_unique
                      // 及其之后的元素仍然存在，但是不知道具体的值是什么）
    print_container(std::cout, words.cbegin(), words.cend()) << std::endl;

    words.erase(end_unique, words.end()); // 删除多余的元素
    print_container(std::cout, words.cbegin(), words.cend()) << std::endl;
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

    return 0;
}
