/**
 * 编写一个 main 函数，令其接受两个实参。
 * 把实参的内容连接成一个 string 对象并输出出来。
 */

#include <iostream>
#include <string>
#include <stdexcept>

using std::cerr;
using std::cout;
using std::endl;
using std::runtime_error;
using std::string;

int main(int argc, char *argv[])
{
    try
    {
        if (argc < 2)
            throw runtime_error("Insufficient arguments");

        string str;
        for (int i = 1; i != argc; ++i)
            str += string(argv[i]) + " ";

        cout << str << endl;
        return 0;
    }
    catch (runtime_error err)
    {
        cerr << err.what() << endl;
        cerr << "The number of arguments should more than 1." << endl;
        return -1;
    }
}
