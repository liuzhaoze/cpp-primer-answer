/**
 * 编写一个程序，从标准输入读取一个字符串，存入一个动态分配的字符数组中。
 * 描述你的程序如何处理变长输入。
 * 测试你的程序，输入一个超出你分配的数组长度的字符串。
 */

#include <cstddef>
#include <iostream>

int main()
{
    std::cout << "How long do you want to input: ";
    std::size_t sz = 0;
    std::cin >> sz;
    char *s = new char[sz + 1]();
    std::cin.ignore();

    std::cout << "Input string: ";
    std::cin.get(s, sz + 1);
    std::cout << s << std::endl;

    delete[] s;
    return 0;
}
