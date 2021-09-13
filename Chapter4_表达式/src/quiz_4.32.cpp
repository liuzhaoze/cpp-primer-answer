/**
 * 解释下面这个循环的含义。
 */

#include <iostream>

int main()
{
    constexpr int size = 5;
    int ia[size] = {1, 2, 3, 4, 5};

    // 循环遍历数组中的元素
    for (int *ptr = ia, ix = 0; ix != size && ptr != ia + size; ++ix, ++ptr) {
        std::cout << *ptr << " " << ia[ix] << std::endl;
    }

    return 0;
}
