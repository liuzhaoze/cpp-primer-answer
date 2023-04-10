/**
 * 编写程序，接受三个参数：一个输入文件和两个输出文件的文件名。
 * 输入文件保存的应该是整数。
 * 使用 istream_iterator 读取输入文件。
 * 使用 ostream_iterator 将奇数写入第一个输出文件，每个值之后都跟一个空格。
 * 将偶数写入第二个输出文件，每个值都独占一行。
 */

#include <algorithm>
#include <fstream>
#include <iterator>
#include <vector>

int main()
{
    std::ifstream ifstrm("../data/absInt");
    std::ofstream of_odd("./quiz_10.33_odd.txt");
    std::ofstream of_even("./quiz_10.33_even.txt");
    std::istream_iterator<int> in_iter(ifstrm), eof;
    std::ostream_iterator<int> out_iter_odd(of_odd, " "), out_iter_even(of_even, "\n");
    std::vector<int> ivec(in_iter, eof);

    std::for_each(ivec.cbegin(), ivec.cend(),
                  [&out_iter_odd, &out_iter_even](const int i) { (i % 2) ? out_iter_odd = i : out_iter_even = i; });

    return 0;
}
