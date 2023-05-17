/**
 * 你在 7.5.1 节的练习 7.40 中曾经选择并编写了一个类，你认为它应该含有关系运算符吗？
 * 如果是，请实现它；如果不是，解释原因。
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
    friend bool operator<(const Book &, const Book &);
    friend bool operator>(const Book &, const Book &);
    friend Book operator+(const Book &, const Book &);

  private:
    unsigned no_;
    std::string name_;
    std::string author_;
    std::string pubdate_;
    unsigned number_;

  public:
    Book() = default;
    Book(unsigned no, std::string const &name, std::string const &author, std::string const &pubdate, unsigned number)
        : no_(no), name_(name), author_(author), pubdate_(pubdate), number_(number)
    {
    }
    explicit Book(std::istream &in)
    {
        in >> *this;
    }

    Book &operator+=(const Book &rhs)
    {
        if (*this == rhs)
        {
            number_ += rhs.number_;
        }

        return *this;
    }
};

std::istream &operator>>(std::istream &in, Book &b)
{
    in >> b.no_ >> b.name_ >> b.author_ >> b.pubdate_;

    if (!in)
    {
        b = Book();
    }

    return in;
}

std::ostream &operator<<(std::ostream &out, const Book &b)
{
    out << b.no_ << " " << b.name_ << " " << b.author_ << " " << b.pubdate_ << " " << b.number_;
    return out;
}

bool operator==(const Book &lhs, const Book &rhs)
{
    return lhs.no_ == rhs.no_;
}

bool operator!=(const Book &lhs, const Book &rhs)
{
    return !(lhs == rhs);
}

bool operator<(const Book &lhs, const Book &rhs)
{
    return lhs.no_ < rhs.no_;
}

bool operator>(const Book &lhs, const Book &rhs)
{
    return rhs < lhs;
}

Book operator+(const Book &lhs, const Book &rhs)
{
    Book sum = lhs;
    sum += rhs;
    return sum;
}

int main()
{
    Book cp5_1(12345, "CP5", "Lippmen", "2012", 2);
    Book cp5_2(12345, "CP5", "Lippmen", "2012", 4);

    std::cout << cp5_1 + cp5_2 << std::endl;

    return 0;
}
