/**
 * 假定我们希望 HasPtr 的行为像一个值。
 * 即，对于对象所指向的 string 成员，每个对象都有一份自己的拷贝。
 * 我们将在下一节介绍拷贝控制成员的定义。
 * 但是，你已经学习了定义这些成员所需的所有知识。
 * 在继续学习下一节之前，为 HasPtr 编写拷贝构造函数和拷贝赋值运算符。
 */

#ifndef _QUIZ_13_22_HPP_
#define _QUIZ_13_22_HPP_

#include <string>

class HasPtr
{
  private:
    int i;
    std::string *ps;

  public:
    HasPtr(const std::string &s = std::string()) : i(0), ps(new std::string(s))
    {
    }

    HasPtr(const HasPtr &hp) : i(hp.i), ps(new std::string(*(hp.ps)))
    {
    }

    HasPtr &operator=(const HasPtr &rhs)
    {
        auto new_ps = new std::string(*(rhs.ps));
        delete ps;

        ps = new_ps;
        i = rhs.i;

        return *this;
    }

    ~HasPtr()
    {
        delete ps;
    }
};

#endif
