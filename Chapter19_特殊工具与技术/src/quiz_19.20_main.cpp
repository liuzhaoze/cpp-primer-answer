/**
 * 将你的 QueryResult 类嵌套在 TextQuery 中，然后重新运行使用了 TextQuery 的程序。
 */

#include "quiz_19.20.hpp"
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
