/**
 * 编写几个正则表达式，分别触发不同错误。
 * 运行你的程序，观察编译器对每个错误的输出。
 */

#include <iostream>
#include <regex>

int main()
{
    try
    {
        std::regex r("[[:alnum:]+\\.(cpp|cxx|cc)$", std::regex::icase);
    }
    catch (std::regex_error e)
    {
        std::cout << e.what() << "\ncode: " << e.code() << std::endl;
    }

    return 0;
}
