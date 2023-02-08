/**
 * 重写上一题的函数，这次使用位置和长度来管理 string ，并只使用 insert 。
 */

#include <iostream>
#include <string>

std::string add_prefix_suffix(std::string name, std::string prefix, std::string suffix)
{
    name.insert(0, prefix + " ");
    name.insert(name.size(), " " + suffix);

    return name;
}

int main()
{
    std::string name = "Wang";

    std::cout << add_prefix_suffix(name, "Mr.", "Jr.") << std::endl;

    return 0;
}
