/**
 * 定义一个类，令其含有指向 StrBlobPtr 对象的指针，为这个类定义重载的箭头运算符。
 */

#include "../../lib/StrBlob.hpp"
#include <iostream>

class StrBlobPtr_pointer
{
  private:
    StrBlobPtr *pointer = nullptr;

  public:
    StrBlobPtr_pointer() = default;
    StrBlobPtr_pointer(StrBlobPtr *p) : pointer(p)
    {
    }

    StrBlobPtr &operator*() const
    {
        return *pointer;
    }
    StrBlobPtr *operator->() const
    {
        return &this->operator*();
    }
};

int main()
{
    StrBlob sb{"hello", "world"};
    StrBlobPtr iter = sb.begin();
    StrBlobPtr_pointer p(&iter);

    std::cout << p->deref() << std::endl;

    return 0;
}
