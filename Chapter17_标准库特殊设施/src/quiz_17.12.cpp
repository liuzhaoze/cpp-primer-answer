/**
 * 使用前一题中的数据结构，编写一个函数，它接受一个问题编号和一个表示真/假解答的值，函数根据这两个参数更新测验的解答。
 */

#include <bitset>
#include <cstddef>
#include <iostream>

void update(std::bitset<100> &answer, std::size_t id, bool solve)
{
    answer.set(id, solve);
}

int main()
{
    std::bitset<100> answer;

    update(answer, 0, true);
    update(answer, 99, true);

    std::cout << answer << std::endl;

    return 0;
}
