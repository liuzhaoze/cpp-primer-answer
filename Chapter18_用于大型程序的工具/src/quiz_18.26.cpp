/**
 * 已知如下所示的继承体系，下面对 print 的调用为什么是错误的？
 * 适当修改 MI ，令其对 print 的调用可以编译通过并正确执行。
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

    // 修改：新建一个接受 int 参数的 print 函数版本
    void print(int i)
    {
        Base1::print(i);
        std::cout << "From overloaded in MI" << std::endl;
    }
};

int main()
{
    MI mi;
    mi.print(42);
    // 错误：原 MI 类中没有能接受 int 实参的 print 函数版本

    return 0;
}
