/**
 * 理解拷贝控制成员和构造函数的一个好方法是定义一个简单的类，为该类定义这些成员，每个成员都打印出自己的名字。
 * 给 X 添加拷贝赋值运算符和析构函数，并编写一个程序以不同方式使用 X 的对象：
 * 1. 将它们作为非引用和引用参数传递
 * 2. 动态分配它们
 * 3. 将它们存放于容器中
 * 观察程序的输出，直到你确认理解了什么时候会使用拷贝控制成员，以及为什么会使用它们。
 * 当你观察程序输出时，记住编译器可以略过对拷贝构造函数的调用。
 */

#include <iostream>
#include <string>
#include <vector>

class X
{
  private:
    std::string s;

  public:
    X() : s(std::string())
    {
        std::cout << "X() 默认构造函数被调用" << std::endl;
    }
    X(const std::string &str) : s(str)
    {
        std::cout << "X(const string &str) 直接初始化函数被调用" << std::endl;
    }
    X(const X &x)
    {
        s = x.s;
        std::cout << "X(const X &x) 拷贝构造函数被调用" << std::endl;
    }
    ~X()
    {
        std::cout << "~X() 析构函数被调用" << std::endl;
    }
    X &operator=(const X &rhs)
    {
        if (this != &rhs)
        {
            s = rhs.s;
            std::cout << "operator=(const X &rhs) 拷贝赋值运算符被调用" << std::endl;
        }
        return *this;
    }
    void print() const
    {
        std::cout << s << std::endl;
    }
};

void f(X a)
{
    a.print();
}
void g(X &b)
{
    b.print();
}

int main()
{
    std::cout << std::string(10, '-') << "初始化" << std::string(10, '-') << std::endl;
    // a 、b 执行默认初始化，c 执行直接初始化
    X a, b, c("ccccc");
    // d 执行拷贝初始化
    X d = c;
    // e 执行拷贝初始化，但是编译器略过了对拷贝构造函数的调用，直接调用了直接初始化
    X e = std::string("eee");
    std::cout << std::string(10, '-') << "初始化结束" << std::string(10, '-') << "\n" << std::endl;

    std::cout << std::string(10, '-') << "作为非引用传递" << std::string(10, '-') << std::endl;
    f(c); // 使用实参 c 拷贝初始化形参 a ，在函数退出时析构形参 a
    std::cout << std::string(10, '-') << "作为非引用传递结束" << std::string(10, '-') << "\n" << std::endl;

    a = c; // 调用拷贝赋值运算符

    std::cout << std::string(10, '-') << "作为引用传递" << std::string(10, '-') << std::endl;
    g(a); // 作为引用传递不会发生拷贝初始化
    std::cout << std::string(10, '-') << "作为引用传递结束" << std::string(10, '-') << "\n" << std::endl;

    std::cout << std::string(10, '-') << "动态分配" << std::string(10, '-') << std::endl;
    X *p = new X("abc"); // 调用直接初始化
    delete p;            // 调用析构函数
    std::cout << std::string(10, '-') << "动态分配结束" << std::string(10, '-') << "\n" << std::endl;

    std::cout << std::string(10, '-') << "存放到容器中" << std::string(10, '-') << std::endl;
    std::vector<X> vx;

    std::cout << std::string(10, '-') << "存放第一个元素" << std::string(10, '-') << std::endl;
    // 使用 string 直接初始化 X 类型的临时对象（即 push_back 的形参），将临时对象拷贝到 vector 中，析构 push_back 的形参
    vx.push_back(std::string("m"));
    std::cout << std::string(10, '-') << "存放第一个元素结束" << std::string(10, '-') << std::endl;

    std::cout << std::string(10, '-') << "存放第二个元素" << std::string(10, '-') << std::endl;
    // 使用 b 拷贝初始化 push_back 的形参，将对象拷贝到 vector 中，析构 push_back 的形参
    vx.push_back(b);
    std::cout << std::string(10, '-') << "存放第二个元素结束" << std::string(10, '-') << std::endl;

    std::cout << std::string(10, '-') << "存放第三个元素" << std::string(10, '-') << std::endl;
    // 使用 string 直接初始化 X 类型的临时对象（即 push_back 的形参），将原来 2 个元素和临时对象拷贝到新 vector
    // 中，析构原 vector 的 2 个对象和 push_back 的形参
    vx.push_back(std::string("n"));
    std::cout << std::string(10, '-') << "存放第三个元素结束" << std::string(10, '-') << std::endl;

    std::cout << std::string(10, '-') << "存放到容器中结束" << std::string(10, '-') << "\n" << std::endl;

    return 0;

    // 析构 a b c d e 和 vector 中的 3 个对象：共 8 个
}
