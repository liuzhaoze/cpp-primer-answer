/**
 * 重写你的电话号码程序，使之允许在号码的三个部分之间放置任意多个空白符。
 */

#include <iostream>
#include <regex>
#include <string>

bool valid(const std::smatch &m)
{
    if (m[1].matched) // 区号有一个左括号
    {
        // 区号必须有一个右括号，并且后面要么紧跟号码，要么只能有一个空格
        return m[3].matched && (!m[5].matched); // NOTE: 修改
    }
    else // 区号没有左括号
    {
        // 区号也不应该有右括号，并且后面两处分隔符要一致
        return (!m[3].matched) && (m[5].str() == m[9].str()); // NOTE: 修改
    }
}

int main()
{
    /**
     * (\\()?   可选的左括号（区号前）
     * (\\d{3}) 区号
     * (\\))?   可选的右括号（区号后）
     * ([ ]*)?  忽略任意长的空格 NOTE: 修改
     * ([-.])?  可选的分隔符    NOTE: 修改
     * ([ ]*)?  忽略任意长的空格 NOTE: 修改
     * (\\d{3}) 前三位号码
     * ([ ]*)?  忽略任意长的空格 NOTE: 修改
     * ([-.])?  可选的分隔符    NOTE: 修改
     * ([ ]*)?  忽略任意长的空格 NOTE: 修改
     * (\\d{4}) 后四位号码
     */
    std::string phone_pattern = "(\\()?(\\d{3})(\\))?([ ]*)?([-.])?([ ]*)?(\\d{3})([ ]*)?([-.])?([ ]*)?(\\d{4})";
    std::regex r(phone_pattern);
    std::smatch m;

    std::string s;
    while (std::getline(std::cin, s))
    {
        for (std::sregex_iterator iter(s.begin(), s.end(), r), end_iter; iter != end_iter; ++iter)
        {
            if (valid(*iter))
            {
                std::cout << "valid: " << iter->str() << std::endl;
            }
            else
            {
                std::cout << "invalid: " << iter->str() << std::endl;
            }
        }
    }

    return 0;
}
