/**
 * 你的 Employee 类需要定义它自己的拷贝控制成员吗？
 * 如果需要，为什么？如果不需要，为什么？
 * 实现你认为 Employee 需要的拷贝控制成员。
 *
 * 答：不需要。因为在现实世界中，拷贝一个员工是没有意义的，一个员工只能是他自己。
 */

#ifndef _QUIZ_13_19_HPP_
#define _QUIZ_13_19_HPP_

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
    Employee(const Employee &) = delete;            // 阻止拷贝
    Employee &operator=(const Employee &) = delete; // 阻止赋值
};

#endif
