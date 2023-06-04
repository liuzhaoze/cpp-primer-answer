/**
 * 重新运行你的一些程序，验证你的 shared_ptr 类和修改后的 Blob 类。
 * （注意：实现 weak_ptr 类型超出了本书范围，因此你不能将 BlobPtr 类与你修改后的 Blob 一起使用。）
 */

#include "quiz_16.29.hpp"
#include <string>

int main()
{
    Blob<std::string> b;

    b.push_back("sss");
    b[0] = "zzzz";

    std::cout << b[0] << std::endl;

    return 0;
}
