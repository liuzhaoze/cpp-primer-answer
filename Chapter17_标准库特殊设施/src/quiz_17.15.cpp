/**
 * 编写程序，使用模式查找违反“ i 在 e 之前，除非在 c 之后”规则的单词。
 * 你的程序应该提示用户输入一个单词，然后指出此单词是否符合要求。
 * 用一些违反和未违反规则的单词测试你的程序。
 *
 * receipt freind theif receive
 */

#include <iostream>
#include <regex>
#include <string>

int main()
{
    // 违反拼写规则的字符串应该是非 c 字母后接 ei 的
    std::string pattern("[^c]ei"); // [^c] 匹配任意不是 c 的字符

    // 使 pattern 能够匹配整个单词
    pattern = "[[:alpha:]]*" + pattern +
              "[[:alpha:]]*"; // [[:alpha:]] 表示任意字母，* 表示零个或多个，如果替换为 + 则表示一个或多个

    // 初始化一个 regex 对象
    std::regex r(pattern);

    // 用于保存搜索结果的对象
    std::smatch results;

    std::string word;
    for (std::cout << "Enter a word: "; std::cin >> word; std::cout << "Enter a word: ")
    {
        if (std::regex_search(word, results, r))
        {
            std::cout << results.str() << " violates the rule" << std::endl;
        }
        else
        {
            std::cout << "legal word" << std::endl;
        }
    }

    return 0;
}
