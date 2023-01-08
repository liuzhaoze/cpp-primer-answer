/**
 * 重写上面的程序，将每个单词作为一个独立的元素进行存储。
 */

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> read_word_in_vector(std::string file_name)
{
    std::ifstream input(file_name);
    std::vector<std::string> str_vec;
    std::string word;

    if (input)
    {
        while (input >> word)
        {
            str_vec.push_back(word);
        }
    }
    else
    {
        std::cerr << "Can't open file: " << file_name << std::endl;
    }

    return str_vec;
}

int main()
{
    std::string file_name = "../data/sstream";
    auto str_vec = read_word_in_vector(file_name);

    for (auto i : str_vec)
    {
        std::cout << i << std::endl;
    }

    return 0;
}
