/**
 * 11.2.1 节练习中的 map 以孩子的姓为关键字，保存他们的名的 vector ，用 multimap 重写此 map 。
 */

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

int main()
{
    std::ifstream ifstrm("../data/family");
    std::multimap<std::string, std::string> family;
    std::string record;

    while (std::getline(ifstrm, record))
    {
        std::istringstream isstrm(record);
        std::string family_name, first_name;

        isstrm >> family_name;
        while (isstrm >> first_name)
        {
            family.emplace(family_name, first_name);
        }
    }

    for (const auto &f : family)
    {
        std::cout << f.first << " " << f.second << std::endl;
    }

    return 0;
}
