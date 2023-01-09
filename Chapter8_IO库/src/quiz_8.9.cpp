/**
 * 使用你为 8.1.2 节第一个练习所编写的函数打印一个 istringstream 对象的内容。
 */

#include "quiz_8.1.hpp"
#include <iostream>
#include <sstream>
#include <string>

int main()
{
    std::string line;

    while (std::getline(std::cin, line))
    {
        std::istringstream strm(line);
        func_quiz_8_1(strm);
    }

    return 0;
}
