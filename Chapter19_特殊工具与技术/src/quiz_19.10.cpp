/**
 * 已知存在如下的类继承体系，其中每个类定义了一个默认公有的构造函数和一个虚析构函数。
 * 下面的语句将打印哪些类型名字？
 */

#include <iostream>
class A
{
  public:
    A() = default;
    virtual ~A() = default;
};

class B : public A
{
  public:
    B() = default;
    virtual ~B() = default;
};

class C : public B
{
  public:
    C() = default;
    virtual ~C() = default;
};

int main()
{
    // (a)
    A *pa = new C;
    std::cout << typeid(pa).name() << std::endl;

    // (b)
    C cobj;
    A &ra1 = cobj;
    std::cout << typeid(&ra1).name() << std::endl;

    // (c)
    B *pb = new B;
    A &ra2 = *pb;
    std::cout << typeid(ra2).name() << std::endl;

    return 0;
}
