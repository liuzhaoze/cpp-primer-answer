/**
 * 修改你的程序，忽略包含“ei”但并非拼写错误的单词，如“albeit”和“neighbor”。
 */

#include <iostream>
#include <regex>
#include <set>
#include <string>

int main()
{
    std::set<std::string> legal = {"albeit", "neighbor"};

    // 违反拼写规则的字符串应该是非 c 字母后接 ei 的
    std::string pattern("[^c]ei"); // [^c] 匹配任意不是 c 的字符

    // 使 pattern 能够匹配整个单词
    pattern = "[[:alpha:]]*" + pattern +
              "[[:alpha:]]*"; // [[:alpha:]] 表示任意字母，* 表示零个或多个，如果替换为 + 则表示一个或多个

    // 初始化一个 regex 对象
    std::regex r(pattern, std::regex::icase); // 忽略大小写

    std::string test_str = "receipt freind albeit neighbor theif receive";

    for (std::sregex_iterator iter(test_str.begin(), test_str.end(), r),
         iter_end; // iter 指向第一个匹配，iter_end 是尾后迭代器
         iter != iter_end; ++iter)
    {
        if (legal.find(iter->str()) != legal.end())
        {
            continue; // 没有拼写错误
        }

        // 打印匹配单词的上文
        auto pos = iter->prefix().length(); // 获得前缀（上文）的大小
        pos = (pos > 40) ? pos - 40 : 0;    // 只输出前缀的后 40 个字符
        std::cout << iter->prefix().str().substr(pos) << "\n";

        std::cout << "\t\t>>> ";
        std::cout << iter->str(); // 每次迭代打印一个匹配的单词（iter 指向 smatch 对象）
        std::cout << " <<<\n";

        // 打印匹配单词的下文
        std::cout << iter->suffix().str().substr(0, 40) << std::endl; // 只输出后缀的前 40 个字符
    }

    return 0;
}
