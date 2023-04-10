/**
 * 使用 find 在一个 int 的 list 中查找最后一个值为 0 的元素。
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>

int main()
{
    std::list<int> ilst = {1, 2, 0, 4, 5, 0, 7, 8};
    auto last_zero = std::find(ilst.crbegin(), ilst.crend(), 0);
    std::cout << "The position of the last zero is " << std::distance(last_zero, ilst.crend()) << std::endl;

    return 0;
}
