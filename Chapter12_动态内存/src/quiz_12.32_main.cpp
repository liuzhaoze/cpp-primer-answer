/**
 * 重写 TextQuery 和 QueryResult 类，用 StrBlob 代替 vector<string> 保存输入文件。
 */

#include "quiz_12.32.hpp"
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
