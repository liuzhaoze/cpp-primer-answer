/**
 * 对于你在练习 7.40 中编写的类，确定哪些构造函数可以使用委托。
 * 如果可以的话，编写委托构造函数。
 * 如果不可以，从抽象概念列表中重新选择一个你认为可以使用委托构造函数的，
 * 为挑选出的这个概念编写类定义。
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
