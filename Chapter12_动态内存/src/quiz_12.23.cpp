/**
 * 编写一个程序，连接两个字符串字面常量，将结果保存在一个动态分配的 char 数组中。
 * 重写这个程序，连接两个标准库 string 对象。
 */

#include <cstddef>
#include <cstring>
#include <iostream>
#include <string>

char *concat(const char *a, const char *b)
{
    char *s = new char[std::strlen(a) + std::strlen(b) + 1]();
    std::strcat(s, a);
    std::strcat(s, b);

    return s;
}

std::string concat(const std::string &a, const std::string &b)
{
    return a + b;
}

int main()
{
    auto a = "Hello", b = "World";

    auto c = concat(a, b);
    std::cout << c << std::endl;
    delete[] c;

    std::cout << concat(std::string(a), std::string(b)) << std::endl;

    return 0;
}
