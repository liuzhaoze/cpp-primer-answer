/**
 * 用 accumulate 求一个 vector<int> 中的元素之和。
 */

#include <fstream>
#include <iostream>
#include <numeric>
#include <vector>

int main()
{
    std::vector<int> ivec;
    std::ifstream ifstrm("../data/absInt");
    int i;

    while (ifstrm >> i)
    {
        ivec.push_back(i);
    }

    std::cout << "Sum is " << std::accumulate(ivec.cbegin(), ivec.cend(), 0) << std::endl;

    return 0;
}
