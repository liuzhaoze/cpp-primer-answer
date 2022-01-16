/**
 * 在 error_msg 函数的第二个版本中包含 ErrCode 类型的参数，其中循环内的 elem 是什么类型？
 */

#include <initializer_list>
#include <string>
#include <iostream>

class ErrCode
{
public:
    std::string msg(void)
    {
        return std::string("Test.");
    }
};

void error_msg(ErrCode e, std::initializer_list<std::string> il)
{
    std::cout << e.msg() << ": ";
    for (const auto &elem : il)
        std::cout << elem << " ";
    std::cout << std::endl;
}

// elem 的类型是 const std::string &
// elem 是常量字符串类型的引用
