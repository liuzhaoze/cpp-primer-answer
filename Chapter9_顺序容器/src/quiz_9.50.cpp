/**
 * 编写程序处理一个 vector<string> ，其中元素都表示整型值。
 * 计算 vector 中所有元素之和。
 * 修改程序，使之计算表示浮点值的 string 之和。
 */

#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::vector<std::string> isvec = {"0", "1", "2", "3", "4", "5"};
    std::vector<std::string> dsvec = {"1.11", "2.2", "3.3", "2.012e2"};
    int isum = 0;
    double dsum = 0.0;

    for (auto each : isvec)
    {
        isum += std::stoi(each);
    }

    for (auto each : dsvec)
    {
        dsum += std::stod(each);
    }

    std::cout << "Sum of int: " << isum << "." << std::endl;
    std::cout << "Sum of double: " << dsum << "." << std::endl;

    return 0;
}
