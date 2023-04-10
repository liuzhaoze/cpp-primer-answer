/**
 * 编写程序，使用流迭代器读取一个文本文件，存入一个 vector 中的 string 里。
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

int main()
{
    std::ifstream ifstrm("../data/accum");
    std::istream_iterator<std::string> in_iter(ifstrm), eof;
    std::ostream_iterator<std::string> out_iter(std::cout, " ");
    std::vector<std::string> svec(in_iter, eof);

    std::copy(svec.begin(), svec.end(), out_iter);
    std::cout << std::endl;

    return 0;
}
