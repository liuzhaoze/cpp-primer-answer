/**
 * 给 make_plural 函数的第二个形参赋予默认实参 's' ，
 * 利用新版本的函数输出单词 success 和 failure 的单数和复数形式。
 */

#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

string make_plural(size_t ctr, const string &word, const string &ending = "s");

int main(int argc, char **argv)
{
    cout << "singual: " << make_plural(1, "success", "es") << " "
         << make_plural(1, "failure") << endl;
    cout << "plural : " << make_plural(2, "success", "es") << " "
         << make_plural(2, "failure") << endl;

    return 0;
}

string make_plural(size_t ctr, const string &word, const string &ending)
{
    return (ctr > 1) ? word + ending : word;
}
