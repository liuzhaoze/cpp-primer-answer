/**
 * 头文件 algorithm 中定义了一个名为 count 的函数，它类似 find ，接受一对迭代器和一个值作为参数。
 * count 返回给定值在序列中出现的次数。
 * 编写程序，读取 int 序列存入 vector 中，打印有多少个元素的值等于给定值。
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

#define TARGET_NUM 23

int main()
{
    std::vector<int> ivec;
    int i;
    std::ifstream ifstrm("../data/iostream_iter");

    while (ifstrm >> i)
    {
        ivec.push_back(i);
    }

    std::cout << "The number of " << TARGET_NUM << " is " << std::count(ivec.cbegin(), ivec.cend(), TARGET_NUM)
              << std::endl;

    return 0;
}
