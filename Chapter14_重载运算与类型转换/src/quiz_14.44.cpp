/**
 * 编写一个简单的桌面计算器使其能处理二元运算。
 */

#include <functional>
#include <iostream>
#include <map>
#include <string>

int add(int i, int j)
{
    return i + j;
}

auto mod = [](int i, int j) { return i % j; };

class Divide
{
  public:
    int operator()(int i, int j) const
    {
        return i / j;
    }
};

std::map<std::string, std::function<int(int, int)>> binops = {
    {"+", add},                                // function pointer
    {"-", std::minus<int>()},                  // library functor
    {"/", Divide()},                           // user-defined functor
    {"*", [](int i, int j) { return i * j; }}, // unnamed lambda
    {"%", mod}                                 // named lambda object
};

int main()
{
    while (true)
    {
        std::cout << "Enter \"<number> <operator> <number>\": ";

        int lhs, rhs;
        std::string op;
        std::cin >> lhs >> op >> rhs;
        std::cout << binops[op](lhs, rhs) << std::endl;
    }

    return 0;
}
