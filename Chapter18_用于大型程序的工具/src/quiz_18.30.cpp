/**
 * 在 Base 中定义一个默认构造函数、一个拷贝构造函数和一个接受 int 形参的构造函数。
 * 在每个派生类中分别定义这三种构造函数，每个构造函数应该使用它的实参初始化其 Base 部分。
 */

class Class
{
};

class Base : public Class
{
  private:
    int ival;

  public:
    // 默认构造函数
    Base() = default;
    // 拷贝构造函数
    Base(const Base &b) : ival(b.ival)
    {
    }
    // 接受 int 形参的构造函数
    Base(int i) : ival(i)
    {
    }
};

class D1 : virtual public Base
{
  public:
    // 默认构造函数
    D1() : Base(){};
    // 拷贝构造函数
    D1(const D1 &d) : Base(d)
    {
    }
    // 接受 int 形参的构造函数
    D1(int i) : Base(i)
    {
    }
};

class D2 : virtual public Base
{
  public:
    // 默认构造函数
    D2() : Base()
    {
    }
    // 拷贝构造函数
    D2(const D2 &d) : Base(d)
    {
    }
    // 接受 int 形参的构造函数
    D2(int i) : Base(i)
    {
    }
};

class MI : public D1, public D2
{
  public:
    // 默认构造函数
    MI() : Base(), D1(), D2()
    {
    }
    // 拷贝构造函数
    MI(const MI &mi) : Base(mi), D1(mi), D2(mi)
    {
    }
    // 接受 int 形参的构造函数
    MI(int i) : Base(i), D1(i), D2(i)
    {
    }
};

class Final : public MI, public Class
{
  public:
    // 默认构造函数
    Final() : Base(), MI(), Class()
    {
    }
    // 拷贝构造函数
    Final(const Final &f) : Base(f), MI(f), Class()
    {
    }
    // 接受 int 形参的构造函数
    Final(int i) : Base(i), MI(i), Class()
    {
    }
};
