/**
 * 为你的类值版本的 HasPtr 编写 swap 函数，并测试它。
 * 为你的 swap 函数添加一个打印语句，指出函数什么时候执行。
 */

#ifndef _QUIZ_13_30_HPP_
#define _QUIZ_13_30_HPP_

#include <iostream>
#include <string>
#include <utility>

class HasPtr
{
  public:
    friend void swap(HasPtr &, HasPtr &);

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

inline void swap(HasPtr &lhs, HasPtr &rhs)
{
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
    std::cout << "HasPtr's swap is called." << std::endl;
}

#endif
