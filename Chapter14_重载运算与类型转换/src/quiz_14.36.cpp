/**
 * 使用前一个练习定义的类读取标准输入，将每一行保存为 vector 的一个元素。
 */

#include "quiz_14.35.hpp"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

int main()
{
    GetString gs;
    std::vector<std::string> svec;
    std::string line;

    while (!(line = gs()).empty())
    {
        svec.push_back(line);
    }

    std::ostream_iterator<std::string> out(std::cout, "\n");
    std::copy(svec.begin(), svec.end(), out);

    return 0;
}
