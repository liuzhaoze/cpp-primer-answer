/**
 * 对一个 string 到 int 的 vector 的 map ，定义并初始化一个变量来保存在其上调用 find 所返回的结果。
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

int main()
{
    std::map<std::string, std::vector<int>> m = {{"first", {0, 1, 2, 3, 4}}, {"second", {5, 6, 7, 8, 9}}};
    std::map<std::string, std::vector<int>>::iterator v;

    v = m.find("second");
    std::for_each(v->second.cbegin(), v->second.cend(), [](const int i) { std::cout << i << " "; });
    std::cout << std::endl;

    return 0;
}
