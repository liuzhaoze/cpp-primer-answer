/**
 * 编写一个类似于 PrintString 的类，令其从 istream 中读取一行输入，然后返回一个表示我们所读内容的 string 。
 * 如果读取失败，返回空 string 。
 */

#ifndef _QUIZ_14_35_HPP_
#define _QUIZ_14_35_HPP_

#include <iostream>
#include <istream>
#include <string>

class GetString
{
  private:
    std::istream &is;

  public:
    GetString(std::istream &i = std::cin) : is(i)
    {
    }

    std::string operator()() const
    {
        std::string line;
        std::getline(is, line);

        return is ? line : std::string();
    }
};

#endif
