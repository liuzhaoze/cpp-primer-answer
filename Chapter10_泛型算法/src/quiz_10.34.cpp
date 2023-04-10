/**
 * 使用 reverse_iterator 逆序打印一个 vector 。
 */

#include <algorithm>
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

    std::copy(svec.crbegin(), svec.crend(), out_iter);
    std::cout << std::endl;

    return 0;
}
