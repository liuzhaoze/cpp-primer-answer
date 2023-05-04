/**
 * 定义一个 Employee 类，它包含雇员的姓名和唯一的雇员证号。
 * 为这个类定义默认构造函数，以及接受一个表示雇员姓名的 string 的构造函数。
 * 每个构造函数应该通过递增一个 static 数据成员来生成一个唯一的证号。
 */

#ifndef _QUIZ_13_18_HPP_
#define _QUIZ_13_18_HPP_

#include <cstddef>
#include <string>

class Employee
{
  public:
    using id_type = std::size_t;

  private:
    std::string name;
    id_type id;
    static id_type unique;

  public:
    Employee() : name(), id(unique++)
    {
    }
    Employee(const std::string &n) : name(n), id(unique++)
    {
    }
};

#endif
