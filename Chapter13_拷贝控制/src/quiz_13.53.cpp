/**
 * 从底层效率的角度看，HasPtr 的赋值运算符并不理想，解释为什么。
 * 为 HasPtr
 * 实现一个拷贝复制运算符和一个移动赋值运算符，并比较你的新的移动赋值运算符中执行的操作和拷贝并交换版本中执行的操作。
 */

#include <chrono>
#include <iostream>
#include <string>

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
        std::cout << "constructor is called" << std::endl;
    }

    HasPtr(const HasPtr &hp) : i(hp.i), ps(new std::string(*(hp.ps)))
    {
        std::cout << "copy constructor is called" << std::endl;
    }

    HasPtr(HasPtr &&hp) noexcept : i(hp.i), ps(hp.ps)
    {
        hp.ps = 0;
        std::cout << "move constructor is called" << std::endl;
    }

    HasPtr &operator=(HasPtr rhs)
    {
        swap(*this, rhs);
        return *this;
    }

    bool operator<(const HasPtr &rhs)
    {
        return *(this->ps) < *(rhs.ps);
    }

    ~HasPtr()
    {
        std::cout << "destructor is called" << std::endl;
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
    std::cout << "swap is called." << std::endl;
}

int main()
{
    HasPtr hp1("hello"), hp2("world"), *php = new HasPtr("World");

    std::cout << std::string(10, '-') << " 使用拷贝构造函数 " << std::string(10, '-') << std::endl;
    auto start = std::chrono::high_resolution_clock::now();
    hp1 = hp2; // 使用拷贝构造函数
    auto end = std::chrono::high_resolution_clock::now();
    auto copy_cost = end - start;

    std::cout << std::string(10, '-') << " 使用移动构造函数 " << std::string(10, '-') << std::endl;
    start = std::chrono::high_resolution_clock::now();
    hp1 = std::move(*php); // 使用移动构造函数
    end = std::chrono::high_resolution_clock::now();
    auto move_cost = end - start;

    std::cout << "拷贝开销：" << copy_cost.count() << std::endl;
    std::cout << "移动开销：" << move_cost.count() << std::endl;

    return 0;
}
