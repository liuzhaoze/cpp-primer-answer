/**
 * 为你的 HasPtr 类定义一个 < 运算符，并定义一个 HasPtr 的 vector 。
 * 为这个 vector 添加一些元素，并对它执行 sort 。
 * 注意何时会调用 swap 。
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

class HasPtr
{
  public:
    friend void swap(HasPtr &, HasPtr &);

  private:
    int i;
    std::string *ps;

  public:
    HasPtr(const std::string &s = std::string()) : i(0), ps(new std::string(s))
    {
    }

    HasPtr(const HasPtr &hp) : i(hp.i), ps(new std::string(*(hp.ps)))
    {
    }

    HasPtr &operator=(const HasPtr &rhs)
    {
        auto new_ps = new std::string(*(rhs.ps));
        delete ps;

        ps = new_ps;
        i = rhs.i;

        return *this;
    }

    bool operator<(const HasPtr &rhs)
    {
        return *(this->ps) < *(rhs.ps);
    }

    ~HasPtr()
    {
        delete ps;
    }

    void print() const
    {
        std::cout << *ps << std::endl;
    }
};

inline void swap(HasPtr &lhs, HasPtr &rhs)
{
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
    std::cout << "HasPtr's swap is called." << std::endl;
}

int main()
{
    std::vector<HasPtr> hpv;

    for (char c = 'z'; c != 'a' - 1; --c)
    {
        hpv.push_back(std::string(1, c));
    }

    std::for_each(hpv.cbegin(), hpv.cend(), [](const HasPtr &hp) { hp.print(); });

    std::sort(hpv.begin(), hpv.end());

    std::for_each(hpv.cbegin(), hpv.cend(), [](const HasPtr &hp) { hp.print(); });

    return 0;
}
