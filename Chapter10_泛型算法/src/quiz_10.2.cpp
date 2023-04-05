/**
 * 重做上一题，但读取 string 序列存入 list 中。
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <list>
#include <string>

#define TARGET_STRING "the"

int main()
{
    std::list<std::string> str_list;
    std::string s;
    std::ifstream ifstrm("../data/accum");

    while (ifstrm >> s)
    {
        str_list.push_back(s);
    }

    std::cout << "The number of \"" << TARGET_STRING << "\" is "
              << std::count(str_list.cbegin(), str_list.cend(), TARGET_STRING) << std::endl;

    return 0;
}
