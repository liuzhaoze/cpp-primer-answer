/**
 * 编写函数，每次调用生成并返回一个均匀分布的随机 unsigned int 。
 */

#include <iostream>
#include <random>

unsigned int random_ui()
{
    static std::default_random_engine e;
    static std::uniform_int_distribution<unsigned int> u;

    return u(e);
}

int main()
{
    std::cout << random_ui() << std::endl;

    return 0;
}
