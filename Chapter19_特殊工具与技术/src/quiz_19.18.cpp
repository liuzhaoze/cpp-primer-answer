/**
 * 编写一个函数，使用 count_if 统计在给定的 vector 中有多少个空 string 。
 */

#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::vector<std::string> svec = {"a", "", "b", "", "c", "", "d"};

    std::cout << std::count_if(svec.begin(), svec.end(), std::mem_fn(&std::string::empty)) << std::endl;

    return 0;
}
