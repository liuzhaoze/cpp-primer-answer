/**
 * 已知如下所示的继承体系，同时假定为 MI 添加了一个名为 foo 的函数：
 * (a) 列出在 MI::foo 中可见的所有名字。
 * (b) 是否存在某个可见的名字是继承自多个基类的？
 * (c) 将 Base1 的 dval 成员与 Derived 的 dval 成员求和后赋给 dval 的局部实例。
 * (d) 将 MI::dvec 的最后一个元素的值赋给 Base2::fval 。
 * (e) 将从 Base1 继承的 cval 赋给从 Derived 继承的 sval 的第一个字符。
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Base1
{
  private:
    int *id;

  protected:
    int ival;
    double dval;
    char cval;

  public:
    void print(int i) const
    {
        std::cout << i << "\tFrom Base1" << std::endl;
    }
};

class Base2
{
  private:
    double dval;

  protected:
    double fval;

  public:
    void print(double d) const
    {
        std::cout << d << "\tFrom Base2" << std::endl;
    }
};

class Derived : public Base1
{
  protected:
    std::string sval;
    double dval;

  public:
    void print(std::string s) const
    {
        std::cout << s << "\tFrom Derived" << std::endl;
    }
};

class MI : public Derived, public Base2
{
  protected:
    int *ival;
    std::vector<double> dvec;

  public:
    void print(std::vector<double> v)
    {
        std::for_each(v.begin(), v.end(), [](const double &d) { std::cout << d << " "; });
        std::cout << "\tFrom MI" << std::endl;
    }
    void foo(double);
};

int ival;
double dval;

void MI::foo(double cval)
{
    int dval;
    // (a) 除了所有基类的私有成员（包括 Base1::id 和 Base2::dval）以外，其他所有名字都在此处可见。
    // (b) 存在，它们是不同基类中同名的非私有成员。访问它们需要使用作用域运算符指定其所在的类。
    dval = Base1::dval + Derived::dval; // (c)
    Base2::fval = dvec.back();          // (d)
    Derived::sval[0] = Base1::cval;     // (e)
}
