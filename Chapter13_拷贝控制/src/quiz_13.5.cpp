/**
 * 给定下面的类框架，编写一个拷贝构造函数，拷贝所有成员。
 * 你的构造函数应该动态分配一个新的 string ，并将对象拷贝到 ps 指向的位置，而不是拷贝 ps 本身。
 */

#include <string>

class HasPtr
{
  private:
    std::string *ps;
    int i;

  public:
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0)
    {
    } // 构造函数
    HasPtr(const HasPtr &hp) : ps(new std::string(*(hp.ps))), i(hp.i)
    {
    } // 拷贝构造函数：申请一个新的 string 将原来的内容拷贝过来，再用指针指向它
};

int main()
{
    HasPtr hp1("hello");
    HasPtr hp2 = hp1;

    return 0;
}
