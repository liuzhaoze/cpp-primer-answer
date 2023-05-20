/**
 * 定义一个函数对象类，令其执行 if-then-else 的操作：
 * 该类的调用运算符接受三个形参，它首先检查第一个形参，如果成功返回第二个形参的值；
 * 如果不成功返回第三个形参的值。
 */

#include <iostream>

class IfThenElse
{
  public:
    int operator()(bool condition, int iA, int iB)
    {
        return condition ? iA : iB;
    }
};

int main()
{
    IfThenElse ite;

    std::cout << ite(1, 10, 20) << std::endl;
    std::cout << ite(0, 10, 20) << std::endl;

    return 0;
}
