/**
 * 编写与本节最后一个程序类似的代码，令其打印你的编译器为一些常见类型所起的名字。
 * 如果你得到的输出结果与本书类似，尝试编写一个函数将这些字符串翻译成人们更容易读懂的形式。
 */

#include "../../lib/Sales_data.hpp"
#include <iostream>
#include <string>

class Base
{
  public:
    Base() = default;
    virtual ~Base() = default;
};

class Derived : public Base
{
  public:
    Derived() = default;
    virtual ~Derived() = default;
};

int main()
{
    int arr[10];
    Derived d;
    Base *p = &d;

    std::cout << typeid(42).name() << ", ";
    std::cout << typeid(arr).name() << ", ";
    std::cout << typeid(Sales_data).name() << ", ";
    std::cout << typeid(std::string).name() << ", ";
    std::cout << typeid(p).name() << ", ";
    std::cout << typeid(*p).name() << std::endl;
}
