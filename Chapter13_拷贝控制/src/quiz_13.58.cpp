/**
 * 编写新版本的 Foo 类，其 sorted 函数中有打印语句，测试这个类，来验证你对前两题的答案是否正确。
 */

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>

// #define QUIZ_13_56
#define QUIZ_13_57

class Foo
{
  private:
    std::vector<int> data;

  public:
    static std::size_t lvalue_count;
    static std::size_t rvalue_count;
    Foo sorted() const &;
    Foo sorted() &&;
};

Foo Foo::sorted() &&
{
    std::sort(data.begin(), data.end());
    std::cout << "rvalue called: " << ++rvalue_count << std::endl;
    return *this;
}

#ifdef QUIZ_13_56
Foo Foo::sorted() const &
{
    Foo ret(*this);
    std::cout << "lvalue called: " << ++lvalue_count << std::endl;
    return ret.sorted();
}
#endif

#ifdef QUIZ_13_57
Foo Foo::sorted() const &
{
    std::cout << "lvalue called: " << ++lvalue_count << std::endl;
    return Foo(*this).sorted();
}
#endif

std::size_t Foo::lvalue_count = 0;
std::size_t Foo::rvalue_count = 0;

int main()
{
    Foo f;
    Foo().sorted();
    f.sorted();

    return 0;
}
