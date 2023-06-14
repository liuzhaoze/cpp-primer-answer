/**
 * 修改上一题中编写的函数，允许用户提供一个种子作为可选参数。
 */

#include <ctime>
#include <iostream>
#include <random>

unsigned int random_ui(unsigned seed = 0)
{
    static std::default_random_engine e(seed);
    static std::uniform_int_distribution<unsigned int> u;

    return u(e);
}

int main()
{
    std::cout << random_ui(time(0)) << std::endl;

    return 0;
}
