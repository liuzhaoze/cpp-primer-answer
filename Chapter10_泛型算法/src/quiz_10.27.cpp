/**
 * 除了 unique 之外，标准库还定义了名为 unique_copy 的函数，它接受第三个迭代器，表示拷贝不重复元素的目的位置。
 * 编写一个程序，使用 unique_copy 将一个 vector 中不重复的元素拷贝到一个初始为空的 list 中。
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <list>
#include <string>
#include <vector>

int main()
{
    std::ifstream ifstrm("../data/accum");
    std::string s;
    std::vector<std::string> vec;
    std::list<std::string> lst;

    while (ifstrm >> s)
    {
        vec.push_back(s);
    }

    // unique 删除的是相邻重复元素，所以 unique 之前必须进行排序
    std::sort(vec.begin(), vec.end());

    std::unique_copy(vec.begin(), vec.end(), std::back_inserter(lst));

    std::for_each(lst.begin(), lst.end(), [](const std::string &s) { std::cout << s << " "; });
    std::cout << std::endl;

    return 0;
}
