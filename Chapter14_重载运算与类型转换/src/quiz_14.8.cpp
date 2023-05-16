/**
 * 你在 7.5.1 节的练习 7.40 中曾经选择并编写了一个类，为它定义一个输出运算符。
 */

#include <iostream>
#include <istream>
#include <ostream>
#include <string>

class Book
{
  public:
    friend std::istream &operator>>(std::istream &, Book &);
    friend std::ostream &operator<<(std::ostream &, const Book &);
    friend bool operator==(const Book &, const Book &);
    friend bool operator!=(const Book &, const Book &);

  private:
    unsigned no_;
    std::string name_;
    std::string author_;
    std::string pubdate_;

  public:
    Book() = default;
    Book(unsigned no, std::string const &name, std::string const &author, std::string const &pubdate)
        : no_(no), name_(name), author_(author), pubdate_(pubdate)
    {
    }
    explicit Book(std::istream &in)
    {
        in >> *this;
    }
};

std::istream &operator>>(std::istream &in, Book &b)
{
    in >> b.no_ >> b.name_ >> b.author_ >> b.pubdate_;
    return in;
}

std::ostream &operator<<(std::ostream &out, const Book &b)
{
    out << b.no_ << " " << b.name_ << " " << b.author_ << " " << b.pubdate_;
    return out;
}

bool operator==(const Book &lhs, const Book &rhs)
{
    return lhs.no_ == rhs.no_;
}

bool operator!=(const Book &lhs, const Book &rhs)
{
    return lhs.no_ != rhs.no_;
}

int main()
{
    Book book1(123, "CP5", "Lippman", "2012");
    Book book2(123, "CP5", "Lippman", "2012");
    Book book3(321, "CP5", "Lippman", "2012");

    if (book1 == book2)
    {
        std::cout << book1 << std::endl;
    }

    if (book2 != book3)
    {
        std::cout << book3 << std::endl;
    }

    return 0;
}
