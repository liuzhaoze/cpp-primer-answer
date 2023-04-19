/**
 * 使用一个 map 迭代器编写一个表达式，将一个值赋予一个元素。
 */

#include <iostream>
#include <map>
#include <string>

int main()
{
    std::map<int, std::string> m;
    m[42] = "Apple";
    std::cout << m[42] << std::endl;

    std::map<int, std::string>::iterator it = m.begin();
    it->second = "Banana";
    std::cout << m[42] << std::endl;

    return 0;
}
