/**
 * 扩展你在 11.2.1 节练习中编写的孩子姓到名的 map ，添加一个 pair 的 vector ，保存孩子的名和生日。
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using Child = std::pair<std::string, std::string>;

int main()
{
    std::ifstream ifstrm("../data/family_extended");
    std::map<std::string, std::vector<Child>> family;
    std::string record;

    while (std::getline(ifstrm, record))
    {
        std::istringstream isstrm(record);
        std::string family_name, first_name, birthday;

        isstrm >> family_name;
        while (isstrm >> first_name >> birthday)
        {
            family[family_name].push_back({first_name, birthday});
        }
    }

    for (const auto &f : family)
    {
        std::cout << f.first << "'s family has " << f.second.size()
                  << ((f.second.size() > 1) ? " children: " : " child: ");
        std::for_each(f.second.cbegin(), f.second.cend(),
                      [](const Child &c) { std::cout << c.first << " " << c.second << " "; });
        std::cout << std::endl;
    }

    return 0;
}
