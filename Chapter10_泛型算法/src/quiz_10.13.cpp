/**
 * 标准库定义了名为 partition 的算法，他接受一个谓词，对容器内容进行划分，使得谓词为 true
 * 的值会排在容器的前半部分，而使谓词为 false 的值会排在后半部分。 算法返回一个迭代器，指向最后一个使谓词为 true
 * 的元素之后的位置。 编写函数，接受一个 string ，返回一个 bool 值，指出 string 是否有 5 个或更多字符。 使用此函数划分
 * words 。 打印出长度大于等于 5 的元素。
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

bool predicate(const std::string &s)
{
    return s.size() >= 5;
}

int main()
{
    std::vector<std::string> words;
    std::string s;
    std::ifstream ifstrm("../data/accum");

    while (ifstrm >> s)
    {
        words.push_back(s);
    }

    auto pivot = std::partition(words.begin(), words.end(), predicate);

    for (auto iter = words.cbegin(); iter != pivot; ++iter)
    {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;

    return 0;
}
