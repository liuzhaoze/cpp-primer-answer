/**
 * 重写本节的电话号码程序，从一个命名文件而非 cin 读取数据。
 */

#include <fstream>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>

struct PersonInfo
{
    std::string name;
    std::vector<std::string> phones;
};

int main()
{
    std::string line, word;
    std::string file_name = "../data/sstream";
    std::vector<PersonInfo> people;
    std::ifstream fstrm(file_name);

    while (std::getline(fstrm, line))
    {
        PersonInfo info;
        std::istringstream record(line);

        record >> info.name;
        while (record >> word)
        {
            info.phones.push_back(word);
        }
        people.push_back(info);
    }

    for (const auto &each : people)
    {
        std::ostringstream ostrm;

        ostrm << each.name << " ";
        for (const auto &num : each.phones)
        {
            ostrm << num << " ";
        }
        std::cout << ostrm.str() << std::endl;
    }

    return 0;
}
