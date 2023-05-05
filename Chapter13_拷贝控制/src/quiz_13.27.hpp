/**
 * 定义你自己的使用引用计数版本的 HasPtr 。
 */

#ifndef _QUIZ_13_27_HPP_
#define _QUIZ_13_27_HPP_

#include <cstddef>
#include <string>

class HasPtr
{
  private:
    int i;
    std::string *ps;
    std::size_t *use;

  public:
    HasPtr(const std::string &s = std::string()) : i(0), ps(new std::string(s)), use(new std::size_t(1))
    {
    }

    HasPtr(const HasPtr &hp) : i(hp.i), ps(hp.ps), use(hp.use)
    {
        ++(*use);
    }

    ~HasPtr()
    {
        if (--(*use) == 0)
        {
            delete ps;
            delete use;
        }
    }

    HasPtr &operator=(const HasPtr &rhs)
    {
        ++(*(rhs.use));

        if (--(*use) == 0)
        {
            delete ps;
            delete use;
        }

        i = rhs.i;
        ps = rhs.ps;
        use = rhs.use;

        return *this;
    }
};

#endif
