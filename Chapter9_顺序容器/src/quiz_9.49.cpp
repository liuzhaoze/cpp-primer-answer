/**
 * 如果一个字母延伸到中线之上，如 d 或 f ，则称其有上出头部分（ ascender ）。
 * 如果一个字母延伸到中线之下，如 p 或 g ，则称其有下出头部分（ descender ）。
 * 编写程序，读入一个单词文件，输出最长的既不包含上出头部分，也不包含下出头部分的单词。
 */

#include <fstream>
#include <iostream>
#include <string>

int main()
{
    std::string path = "../data/letter.txt";
    std::ifstream fin(path);
    std::string target_letter = "acemnorsuvwxz";
    std::string longest_fitting_word;
    auto length = longest_fitting_word.size();
    std::string word;

    while (fin >> word)
    {
        if (word.find_first_not_of(target_letter) == std::string::npos)
        {
            if (word.size() > length)
            {
                longest_fitting_word = word;
                length = longest_fitting_word.size();
            }
        }
    }

    std::cout << "The longest fitting word is " << longest_fitting_word << " length: " << length << std::endl;

    return 0;
}
