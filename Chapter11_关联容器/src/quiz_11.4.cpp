/**
 * 扩展你的程序，忽略大小写和标点。
 * 例如，"example." 、"example," 和 "Example" 应该递增相同的计数器。
 */

#include <cctype>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

std::string strip(std::string s)
{
    for (auto &c : s)
    {
        c = std::tolower(c);
    }
    s.erase(std::remove_if(s.begin(), s.end(), std::ispunct), s.end());
    return s;

    /**
     * remove_if 返回一个迭代器，指向被移除后的新容器的结尾位置。
     * remove_if 仅仅是将满足条件的元素移动到容器尾部，并不会真正删除这些元素。
     * ※ 算法不会改变容器的大小
     * 因此需要再将这些被移动到容器尾部的元素用 erase 函数真正地从容器中删除掉。
     * 如果只使用 remove_if 而不使用 erase ，则容器中仍会保留这些被移动到容器尾部的元素。
     */
}

int main()
{
    std::ifstream ifstrm("../data/word_count");
    std::map<std::string, std::size_t> word_count;
    std::string word;

    while (ifstrm >> word)
    {
        ++word_count[strip(word)];
    }

    for (const auto &w : word_count)
    {
        std::cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times." : " time.") << std::endl;
    }

    return 0;
}
