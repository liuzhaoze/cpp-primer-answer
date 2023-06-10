/**
 * 使用序列 1 、2 、3 、5 、8 、13 、21 初始化一个 bitset，将这些位置位。
 * 对另一个 bitset 进行默认初始化，并编写一小段程序将其恰当的位置位。
 */

#include <bitset>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> ivec = {1, 2, 3, 5, 8, 13, 21};
    unsigned long ul = 0;

    for (const auto &pos : ivec)
    {
        ul |= (1u << pos);
    }

    std::bitset<32> b1(ul);
    std::bitset<32> b2;

    for (decltype(b1.size()) i = 0; i != b1.size(); ++i)
    {
        b2[i] = b1[i];
    }

    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;

    return 0;
}
