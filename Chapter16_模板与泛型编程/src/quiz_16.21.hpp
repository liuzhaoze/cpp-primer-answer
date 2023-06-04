/**
 * 编写你自己的 DebugDelete 版本。
 */

#ifndef _QUIZ_16_21_HPP_
#define _QUIZ_16_21_HPP_

#include <iostream>
#include <ostream>

class DebugDelete
{
  private:
    std::ostream &os;

  public:
    DebugDelete(std::ostream &s = std::cerr) : os(s)
    {
    }

    template <typename T> void operator()(T *p) const
    {
        os << "deleting pointer" << std::endl;
        delete p;
    }
};

#endif
