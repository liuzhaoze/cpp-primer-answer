/**
 * 重写上一题的程序，比较一个 list<int> 中的元素和一个 vector<int> 中的元素。
 */

#include <iostream>
#include <list>
#include <vector>

int main()
{
    std::list<int> ilist{1, 2, 3, 4, 5};
    std::vector<int> ivec2{1, 2, 3, 4, 5};
    std::vector<int> ivec3{1, 2, 3, 4};

    // 将 list<int> 转化为 vector<int> 之后再比较
    std::cout << (std::vector<int>(ilist.begin(), ilist.end()) == ivec2) << std::endl;
    std::cout << (std::vector<int>(ilist.begin(), ilist.end()) == ivec3) << std::endl;

    return 0;
}
