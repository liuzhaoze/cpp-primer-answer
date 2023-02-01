/**
 * 编写程序，从标准输入读取 string 序列，存入一个 deque 中。
 * 编写一个循环，用迭代器打印 deque 中的元素。
 */

#include <deque>
#include <iostream>
#include <string>

int main()
{
    std::deque<std::string> dq;
    std::string word;

    while (std::cin >> word)
    {
        dq.push_back(word);
    }

    for (auto iter = dq.cbegin(); iter != dq.cend(); ++iter)
    {
        std::cout << *iter << std::endl;
    }

    return 0;
}
