/**
 * 重写你的电话号码程序，使之对多于一个电话号码的人只输出第二个和后续电话号码。
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <ostream>
#include <regex>
#include <sstream>
#include <string>
#include <vector>

struct PersonInfo
{
    std::string name;
    std::vector<std::string> phones;
};

// NOTE: 修改
std::ostream &operator<<(std::ostream &os, const PersonInfo person)
{
    os << person.name << ": ";

    if (person.phones.size() == 1)
    {
        os << person.phones.front();
    }
    else if (person.phones.size() > 1)
    {
        std::ostream_iterator<std::string> os_iter(os, " ");
        std::copy(++person.phones.cbegin(), person.phones.cend(), os_iter);
    }

    return os;
}

bool valid(const std::smatch &m)
{
    if (m[1].matched) // 区号有一个左括号
    {
        // 区号必须有一个右括号，并且后面要么紧跟号码，要么只能有一个空格
        return m[3].matched && (m[4].matched == 0 || m[4].str() == " ");
    }
    else // 区号没有左括号
    {
        // 区号也不应该有右括号，并且后面两处分隔符要一致
        return (!m[3].matched) && (m[4].str() == m[6].str());
    }
}

std::string format(const std::string &number, const std::regex &r)
{
    return std::regex_replace(number, r, "$2.$5.$7");
}

int main()
{
    /**
     * (\\()?   可选的左括号（区号前）
     * (\\d{3}) 区号
     * (\\))?   可选的右括号（区号后）
     * ([-. ])? 可选的分隔符
     * (\\d{3}) 前三位号码
     * ([-. ])? 可选的分隔符
     * (\\d{4}) 后四位号码
     */
    std::string phone_pattern = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
    std::regex r(phone_pattern);
    std::smatch m;

    std::vector<PersonInfo> people;

    std::ifstream in_file("../data/phones2"); // NOTE: 修改
    std::string line;
    while (std::getline(in_file, line))
    {
        PersonInfo info;
        std::istringstream record(line);

        record >> info.name;
        auto phones = record.str();

        for (std::sregex_iterator iter(phones.begin(), phones.end(), r), end_iter; iter != end_iter; ++iter)
        {
            if (valid(*iter))
            {
                std::cout << "valid number: " << iter->str() << std::endl;
                info.phones.push_back(format(iter->str(), r));
            }
            else
            {
                std::cout << "invalid number: " << iter->str() << std::endl;
            }
        }

        people.push_back(info);
    }

    std::for_each(people.cbegin(), people.cend(), [](const auto &each) { std::cout << each << std::endl; });

    return 0;
}
