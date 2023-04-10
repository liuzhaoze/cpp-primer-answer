/**
 * 使用普通迭代器逆序打印一个 vector 。
 */

#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

int main()
{
    std::ifstream ifstrm("../data/count-size");
    std::istream_iterator<std::string> in_iter(ifstrm), eof;
    std::ostream_iterator<std::string> out_iter(std::cout, " ");
    std::vector<std::string> svec(in_iter, eof);

    for (auto it = std::prev(svec.cend()); it != std::prev(svec.cbegin()); --it)
    {
        out_iter = *it;
    }
    std::cout << std::endl;

    return 0;
}
