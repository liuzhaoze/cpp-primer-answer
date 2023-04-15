/**
 * 定义一个 map ，关键字是家庭的姓，值是一个 vector ，保存家中孩子（们）的名。
 * 编写代码，实现添加新的家庭以及向已有家庭中添加新的孩子。
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <sstream>
#include <string>
#include <vector>

int main()
{
    std::ifstream ifstrm("../data/family");
    std::map<std::string, std::vector<std::string>> family;
    std::string record;

    while (std::getline(ifstrm, record))
    {
        std::istringstream isstrm(record);
        std::string family_name, first_name;

        isstrm >> family_name;
        while (isstrm >> first_name)
        {
            family[family_name].push_back(first_name);
        }
    }

    for (const auto &f : family)
    {
        std::cout << f.first << "'s family has " << f.second.size()
                  << ((f.second.size() > 1) ? " children: " : " child: ");
        std::ostream_iterator<std::string> out_iter(std::cout, " ");
        std::copy(f.second.cbegin(), f.second.cend(), out_iter);
        std::cout << std::endl;
    }

    return 0;
}
