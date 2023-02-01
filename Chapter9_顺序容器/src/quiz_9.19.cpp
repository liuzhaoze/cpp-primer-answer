/**
 * 重写上题的程序，用 list 替代 deque。
 * 列出程序要做出哪些改变。
 */

#include <iostream>
#include <list>
#include <string>

int main()
{
    std::list<std::string> lst;
    std::string word;

    while (std::cin >> word)
    {
        lst.push_back(word);
    }

    for (auto iter = lst.cbegin(); iter != lst.cend(); ++iter)
    {
        std::cout << *iter << std::endl;
    }

    return 0;
}
