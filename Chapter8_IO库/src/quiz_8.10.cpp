/**
 * 编写程序，将来自一个文件中的行保存在一个 vector<string> 中。
 * 然后使用一个 istringstream 从 vector 读取数据元素，每次读取一个单词。
 */

#include <fstream>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>


int main()
{
    std::vector<std::string> lines;
    std::string line;
    std::string file_name = "../data/sstream";
    std::fstream fstrm(file_name);

    while (std::getline(fstrm, line))
    {
        lines.push_back(line);
    }

    for (auto each : lines)
    {
        std::istringstream sstrm(each);
        std::string word;

        while (sstrm >> word)
        {
            std::cout << word << std::endl;
        }
    }

    return 0;
}
