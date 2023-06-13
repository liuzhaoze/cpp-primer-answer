/**
 * 如果前一题程序中的 regex 对象用 "[^c]ei" 进行初始化，将会发生什么？
 * 用此模式测试你的程序，检查你的答案是否正确。
 *
 * 答：仍然能匹配违反规则的序列，但是匹配结果只储存三个字符，而不是整个单词。
 */

#include <iostream>
#include <regex>
#include <string>

int main()
{
    // 违反拼写规则的字符串应该是非 c 字母后接 ei 的
    std::string pattern("[^c]ei"); // [^c] 匹配任意不是 c 的字符

    // // 使 pattern 能够匹配整个单词
    // pattern = "[[:alpha:]]*" + pattern +
    //           "[[:alpha:]]*"; // [[:alpha:]] 表示任意字母，* 表示零个或多个，如果替换为 + 则表示一个或多个

    // 初始化一个 regex 对象 NOTE: 只用 "[^c]ei" 进行初始化
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
