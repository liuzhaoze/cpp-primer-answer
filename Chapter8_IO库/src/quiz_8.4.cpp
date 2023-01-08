/**
 * 编写函数，以读模式打开一个文件，将其内容读入到一个 string 的 vector 中，
 * 将每一行作为一个独立的元素存于 vector 中。
 */

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> read_line_in_vector(std::string file_name)
{
    std::ifstream input(file_name);
    std::vector<std::string> str_vec;
    std::string line;

    if (input)
    {
        while (std::getline(input, line))
        {
            str_vec.push_back(line);
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
    auto str_vec = read_line_in_vector(file_name);

    for (auto i : str_vec)
    {
        std::cout << i << std::endl;
    }

    return 0;
}
