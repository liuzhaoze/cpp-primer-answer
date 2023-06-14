/**
 * 再次修改你的程序，此次再增加两个参数，表示函数允许返回的最小值和最大值。
 */

#include <ctime>
#include <iostream>
#include <random>

unsigned int random_ui(unsigned min, unsigned max, unsigned seed = 0)
{
    static std::default_random_engine e(seed);
    static std::uniform_int_distribution<unsigned int> u(min, max);

    return u(e);
}

int main()
{
    std::cout << random_ui(0, 500, time(0)) << std::endl;

    return 0;
}
