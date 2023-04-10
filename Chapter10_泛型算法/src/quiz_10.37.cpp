/**
 * 给定一个包含 10 个元素的 vector ，将位置 3 到 7 之间的元素按逆序拷贝到一个 list 中。
 */

#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

int main()
{
    std::vector<int> ivec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::list<int> ilst(8 - 3);

    std::copy(ivec.cbegin() + 3, ivec.cbegin() + 8, ilst.rbegin());

    std::for_each(ilst.cbegin(), ilst.cend(), [](const int i) { std::cout << i << " "; });
    std::cout << std::endl;

    return 0;
}
