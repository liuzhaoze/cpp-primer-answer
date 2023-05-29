/**
 * 对于你在上一题中选择的类，为其添加合适的虚函数，以及公有成员和受保护的成员。
 */

#ifndef _QUIZ_15_22_HPP_
#define _QUIZ_15_22_HPP_

#include <string>
#include <utility>

class Shape
{
  public:
    // 坐标
    using Coordinate = std::pair<double, double>;

  private:
    std::string name;

  public:
    Shape() = default;
    Shape(const std::string &n) : name(n)
    {
    }
    virtual ~Shape() = default;

    virtual double area() const = 0;
    virtual double perimeter() const = 0;
};

class Rectangle : public Shape
{
  protected:
    Coordinate a, b, c, d;

  public:
    Rectangle() = default;
    Rectangle(const std::string &n, const Coordinate &a, const Coordinate &b, const Coordinate &c, const Coordinate &d)
        : Shape(n), a(a), b(b), c(c), d(d)
    {
    }
    ~Rectangle() = default;
};

class Square : public Rectangle
{
  public:
    Square() = default;
    Square(const std::string &n, const Coordinate &a, const Coordinate &b, const Coordinate &c, const Coordinate &d)
        : Rectangle(n, a, b, c, d)
    {
    }
    ~Square() = default;
};

#endif
