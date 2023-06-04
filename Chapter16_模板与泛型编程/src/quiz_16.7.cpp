/**
 * 编写一个 constexpr 模板，返回给定数组的大小。
 */

#include <iostream>
#include <string>

template <typename T, unsigned size> constexpr unsigned get_size(const T (&arr)[size])
{
    return size;
}

int main()
{
    std::string s[] = {"a", "bb"};
    char c[] = "abc";

    std::cout << get_size(s) << std::endl;
    std::cout << get_size(c) << std::endl;

    return 0;
}
