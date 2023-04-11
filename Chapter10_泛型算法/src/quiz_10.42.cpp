/**
 * 使用 list 代替 vector 重新实现 10.2.3 节中的去除重复单词的程序。
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <list>
#include <string>

void elimDups(std::list<std::string> &words)
{
    words.sort();
    words.unique();
}

int main()
{
    std::ifstream ifstrm("../data/accum");
    std::istream_iterator<std::string> in_iter(ifstrm), eof;
    std::ostream_iterator<std::string> out_iter(std::cout, " ");
    std::list<std::string> slst(in_iter, eof);

    elimDups(slst);

    std::copy(slst.cbegin(), slst.cend(), out_iter);
    std::cout << std::endl;

    return 0;
}
