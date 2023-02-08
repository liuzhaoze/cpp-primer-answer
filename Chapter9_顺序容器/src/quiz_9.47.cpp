/**
 * 编写程序，首先查找 string "ab2c3d7R4E6" 中的每个数字字符，然后查找其中每个字母字符。
 */

#include <iostream>
#include <string>

int main()
{
    std::string s = "ab2c3d7R4E6";
    std::string::size_type pos = 0;
    std::string numbers = "0123456789";

    while ((pos = s.find_first_of(numbers, pos)) != std::string::npos)
    {
        std::cout << "found number at index: " << pos << " element is: " << s[pos] << std::endl;
        ++pos;
    }

    pos = 0;
    std::cout << std::endl;
    while ((pos = s.find_first_not_of(numbers, pos)) != std::string::npos)
    {
        std::cout << "found letter at index: " << pos << " element is: " << s[pos] << std::endl;
        ++pos;
    }

    return 0;
}
