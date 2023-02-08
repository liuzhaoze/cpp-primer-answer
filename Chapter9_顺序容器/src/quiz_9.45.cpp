/**
 * 编写一个函数，接受一个表示名字的 string 参数和两个分别表示前缀（如 "Mr." 或 "Ms."）和后缀（如 "Jr." 或
 * "III"）的字符串。 使用迭代器及 insert 和 append 函数，将前缀和后缀添加到给定的名字中，将生成的新 string 返回。
 */

#include <iostream>
#include <string>

std::string add_prefix_suffix(std::string name, std::string prefix, std::string suffix)
{
    name.insert(name.begin(), 1, ' ');
    name.insert(name.begin(), prefix.cbegin(), prefix.cend());

    name.append(" " + suffix);

    return name;
}

int main()
{
    std::string name = "Wang";

    std::cout << add_prefix_suffix(name, "Mr.", "Jr.") << std::endl;

    return 0;
}
