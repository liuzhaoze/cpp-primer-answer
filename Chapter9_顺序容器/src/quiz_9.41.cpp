/**
 * 编写程序，从一个 vector<char> 初始化一个 string 。
 */

#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::vector<char> cvec = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd'};
    std::string s(cvec.cbegin(), cvec.cend());

    std::cout << s << std::endl;

    return 0;
}
