/**
 * 从下面的抽象概念中选择一个，思考这样的类需要哪些数据成员，
 * 提供一组合理的构造函数并阐明这样做的原因。
 * Book, Date, Employee, Vehicle, Object, Tree
 */

#include <iostream>
#include <string>

class Book
{
public:
    Book(unsigned isbn, std::string const &name, std::string const &author, std::string const &pubdate)
        : isbn_(isbn), name_(name), author_(author), pubdate_(pubdate)
    {
    }

    explicit Book(std::istream &in)
    {
        in >> isbn_ >> name_ >> author_ >> pubdate_;
    }

private:
    unsigned isbn_;
    std::string name_;
    std::string author_;
    std::string pubdate_;
};
