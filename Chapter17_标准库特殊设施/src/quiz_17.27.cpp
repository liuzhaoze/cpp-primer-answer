/**
 * 编写程序，将 9 位数字邮政编码的格式转换为 ddddd-dddd 。
 */

#include <iostream>
#include <regex>
#include <string>

bool valid(const std::smatch &m)
{
    if ((m[2].matched) && (!m[3].matched))
    {
        return false;
    }
    else
    {
        return true;
    }
}

// NOTE: 修改
std::string format(const std::smatch &m)
{
    return (m[3].matched ? m.format("$1-$3") : m.str());
}

int main()
{
    std::string zipcode = "(\\d{5})([-])?(\\d{4})?\\b";
    std::regex r(zipcode);
    std::smatch m;
    std::string s;

    while (getline(std::cin, s))
    {
        for (std::sregex_iterator it(s.begin(), s.end(), r), end_it; it != end_it; ++it)
        {
            if (valid(*it))
            {
                std::cout << "valid zipcode: " << it->str() << "\n\tformatted: " << format(*it)
                          << std::endl; // NOTE: 修改
            }
            else
            {
                std::cout << "invalid zipcode: " << it->str() << std::endl;
            }
        }
    }

    return 0;
}
