/**
 * 编写查找邮政编码的正则表达式。
 * 一个美国邮政编码可以由 5 位或 9 位数字组成。
 * 前 5 位数字和后 4 位数字之间可以用一个短横线分割。
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
                std::cout << "valid zipcode: " << it->str() << std::endl;
            }
            else
            {
                std::cout << "invalid zipcode: " << it->str() << std::endl;
            }
        }
    }

    return 0;
}
