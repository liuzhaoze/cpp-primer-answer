/**
 * 修改 12.3 节中你的 TextQuery 程序，令 shared_ptr 成员使用 DebugDelete 作为它们的删除器。
 */

#include "quiz_16.22.hpp"
#include <fstream>
#include <iostream>
#include <string>

void runQueries(std::ifstream &infile)
{
    TextQuery tq(infile);

    while (true)
    {
        std::cout << "Enter word to look for, or \'q\' to quit: ";
        std::string s;

        if (!(std::cin >> s) || s == "q")
        {
            std::cout << "Exited." << std::endl;
            break;
        }

        print(std::cout, tq.query(s)) << std::endl;
    }
}

int main()
{
    std::ifstream infile("../data/storyDataFile");
    runQueries(infile);

    return 0;
}
