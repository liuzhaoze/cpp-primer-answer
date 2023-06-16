/**
 * 修改下面的 main 函数，使其能捕获 18.1.5 小节所示的任何异常类型：
 * int main()
 * {
 *     // 使用 C++ 标准库
 * }
 * 处理代码应该首先打印异常相关的错误信息，然后调用 abort（定义在 cstdlib 头文件中）终止 main 函数。
 */

#include <cstdlib>
#include <exception>
#include <iostream>
#include <stdexcept>

int main(int argc, char *argv[])
{
    try
    {
        if (argc == 1)
        {
            throw std::invalid_argument("invalid_argument");
        }
    }
    catch (std::exception e)
    {
        std::cerr << e.what() << std::endl;
        std::abort();
    }

    std::cout << "nothing happened" << std::endl;
    return 0;
}
