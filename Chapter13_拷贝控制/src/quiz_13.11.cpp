/**
 * 为前面练习中的 HasPtr 类添加一个析构函数。
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
    ~HasPtr()
    {
        delete ps;
    } // 析构函数
    HasPtr &operator=(const HasPtr &rhs_hp)
    {
        if (this != &rhs_hp)
        {
            std::string *temp = new std::string(*(rhs_hp.ps));
            delete ps;
            ps = temp;
            i = rhs_hp.i;
        }
        return *this;
    } // 赋值运算符：申请一个新的 string ，释放原来的 string ，将 ps 指向新的 string 并拷贝 i
};

int main()
{
    HasPtr hp1("hello");
    HasPtr hp2;

    hp2 = hp1;

    return 0;
}
