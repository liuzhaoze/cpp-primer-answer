/**
 * 解释下面程序片段做了什么。
 */

#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::vector<std::string> svec; // 定义了一个空的 string vector
    svec.reserve(1024);            // 为 svec 分配了 1024 个元素的内存空间
    std::string word;              // 定义了一个空字符串

    while (std::cin >> word)
    {
        svec.push_back(word); // 从标准输入中读取一个单词，并将其放入 svec 中
    }

    svec.resize(svec.size() + svec.size() / 2);
    // 将 svec 的元素数量设置为当前元素数量的 1.5 倍
    // 多出来的一半元素将被值初始化为空字符串

    return 0;
}
