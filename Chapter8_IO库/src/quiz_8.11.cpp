/**
 * 本节的程序在最外层 while 循环中定义了 istringstream 对象。
 * 如果 record 对象定义在循环之外，你需要对程序进行怎样的修改？
 * 重写程序，将 record 的定义移到 while 循环之外，验证你设想的修改方法是否正确。
 */

#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>

struct PersonInfo
{
    std::string name;
    std::vector<std::string> phones;
};

int main()
{
    std::string line, word;
    std::vector<PersonInfo> people;
    std::istringstream record;

    while (std::getline(std::cin, line))
    {
        PersonInfo info;

        record.clear(); // NOTE: record 定义在 while 外面时，流的失效状态会保留，需要手动清除
        record.str(line);
        record >> info.name;
        while (record >> word)
        {
            info.phones.push_back(word);
        }
        people.push_back(info);
    }

    for (auto each : people)
    {
        std::cout << each.name << " ";
        for (auto number : each.phones)
        {
            std::cout << number << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
