/**
 * 编写程序，判定两个 vector<int> 是否相等。
 */

#include <iostream>
#include <ostream>
#include <vector>

int main()
{
    std::vector<int> v1 = {1, 3, 5, 7, 9, 12};
    std::vector<int> v2 = {1, 3, 9};
    std::vector<int> v3 = {1, 3, 5, 7, 9, 12};

    std::cout << (v1 == v2) << std::endl;
    std::cout << (v1 == v3) << std::endl;

    return 0;
}
