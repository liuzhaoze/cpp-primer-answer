/**
 * 扩展上一题中你的程序，将读入的每个单词打印到它所在的行。
 */

#include <fstream>
#include <iostream>

int main()
{
    std::ifstream in_file("../data/test");
    char sink[250];

    while (in_file.getline(sink, 250, ' '))
    {
        std::cout << sink << std::endl;
    }

    return 0;
}
