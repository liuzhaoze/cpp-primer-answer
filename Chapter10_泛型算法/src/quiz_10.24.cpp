/**
 * 给定一个 string ，使用 bind 和 check_size 在一个 int 的 vector 中查找第一个大于 string 长度的值。
 */

#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

bool check_size(const std::string &s, int i)
{
    return i > s.size();
}

int main()
{
    std::string str = "abcdefg";
    std::vector<int> ivec = {1, 2, 3, 4, 5, 99, 5, 4, 3, 2, 1};

    auto p = std::find_if(ivec.begin(), ivec.end(), std::bind(check_size, str, std::placeholders::_1));

    std::cout << "The first value which is larger than the size of string is " << *p << std::endl;

    return 0;
}
