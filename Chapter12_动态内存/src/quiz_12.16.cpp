/**
 * 如果你试图拷贝或赋值 unique_ptr ，编译器并不总是能给出易于理解的错误信息。
 * 编写包含这种错误的程序，观察编译器如何诊断这种错误。
 */

#include <memory>
#include <string>

int main()
{
    std::unique_ptr<std::string> p1(new std::string("Stegosaurus"));

    std::unique_ptr<std::string> p2(p1);
    // error: call to deleted constructor of 'std::unique_ptr<std::string>' (aka 'unique_ptr<basic_string<char>>')

    std::unique_ptr<std::string> p3;
    p3 = p1;
    // error: overload resolution selected deleted operator '='

    return 0;
}
