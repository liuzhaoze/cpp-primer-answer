/**
 * 编写程序，逐行读入一个输入文件，将内容存入一个 StrBlob 中，用一个 StrBlobPtr 打印出 StrBlob 中的每个元素。
 */

#include "../../lib/StrBlob.hpp"
#include <fstream>
#include <iostream>
#include <string>

int main()
{
    std::ifstream ifstrm("../data/storyDataFile");
    std::string line;
    StrBlob sb;

    while (std::getline(ifstrm, line))
    {
        sb.push_back(line);
    }

    for (auto beg = sb.begin(), end = sb.end(); beg != end; beg.incr())
    {
        std::cout << beg.deref() << std::endl;
    }

    return 0;
}
