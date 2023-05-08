/**
 * 在你的 TextQuery 和 QueryResult 类中用你的 StrVec 类代替 vector<string> ，以此来测试你的 StrVec 类。
 * clang++ quiz_13.42_main.cpp quiz_13.42.cpp ../../lib/StrVec.cpp -o a.exe
 */

#include "quiz_13.42.hpp"
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
