/**
 * 我们曾经用 do while 循环来编写管理用户交互的循环。
 * 用 do while 重写本节程序，解释你倾向于哪个版本，为什么。
 *
 * 答：我觉得两者没什么区别。
 * while 先检查条件再决定是否执行循环体；
 * do while 先执行一遍循环体再检查条件决定是否继续执行。
 * 本节程序条件恒为 true ，没什么区别。
 */

#include "quiz_12.27.hpp"
#include <fstream>
#include <iostream>
#include <string>

void runQueries(std::ifstream &infile)
{
    TextQuery tq(infile);

    do
    {
        std::cout << "Enter word to look for, or \'q\' to quit: ";
        std::string s;

        if (!(std::cin >> s) || s == "q")
        {
            std::cout << "Exited." << std::endl;
            break;
        }

        print(std::cout, tq.query(s)) << std::endl;
    } while (true);
}

int main()
{
    std::ifstream infile("../data/storyDataFile");
    runQueries(infile);

    return 0;
}
