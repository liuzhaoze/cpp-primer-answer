/**
 * 编写一个整型对象，包含真/假测验的正确答案。
 * 使用它来为前两题中的数据结构生成测验成绩。
 */

#include <bitset>
#include <cstddef>
#include <iostream>
#include <string>

void update(std::bitset<100> &answer, std::size_t id, bool solve)
{
    answer.set(id, solve);
}

int main()
{
    constexpr std::size_t num = 100;
    std::bitset<num> correct(
        "1100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000011");
    std::bitset<num> answer;

    update(answer, 0, true);
    update(answer, 99, true);

    std::cout << "score: " << (answer ^ correct).flip().count() << std::endl;

    return 0;
}
