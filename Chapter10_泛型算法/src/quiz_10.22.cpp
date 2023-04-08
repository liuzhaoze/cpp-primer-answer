/**
 * 重写统计长度小于等于 6 的单词数量的程序，使用函数代替 lambda 。
 */

#include <algorithm>
#include <fstream>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

bool is_less_than_or_equal_to(const std::string &s, std::string::size_type sz)
{
    return s.size() <= sz;
}

int main()
{
    std::ifstream ifstrm("../data/accum");
    std::vector<std::string> svec;
    std::string s;
    std::string::size_type sz = 6;

    while (ifstrm >> s)
    {
        svec.push_back(s);
    }

    int count = std::count_if(svec.begin(), svec.end(), std::bind(is_less_than_or_equal_to, std::placeholders::_1, sz));

    std::cout << "Word less than or equal to " << sz << " counts " << count << std::endl;

    return 0;
}
