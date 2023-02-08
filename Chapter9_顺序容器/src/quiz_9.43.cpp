/**
 * 编写一个函数，接受三个 string 参数 s 、 oldVal 、 newVal 。
 * 使用迭代器及 insert 和 erase 函数将 s 种所有 oldVal 替换为 newVal 。
 * 测试你的程序，用它替换通用的简写形式，如，将 tho 替换为 though ，将 thru 替换为 through 。
 */

#include <iostream>
#include <string>

void my_replace(std::string &s, const std::string oldVal, const std::string newVal)
{
    for (auto iter = s.begin(); iter != (s.end() - oldVal.size() + 1); ++iter)
    {
        if (std::string(iter, iter + oldVal.size()) == oldVal)
        {
            // 注意添加或删除元素会使后面的元素迭代器失效
            iter = s.erase(iter, iter + oldVal.size());
            iter = s.insert(iter, newVal.cbegin(), newVal.cend());
            iter += newVal.size() - 1; // for 循环中有 ++iter
        }
    }
}

int main()
{
    std::string s = "To drive straight thru is a foolish, tho courageous act.";

    my_replace(s, "tho", "though");
    my_replace(s, "thru", "through");
    std::cout << s << std::endl;

    return 0;
}
