/**
 * 编写标准库 string 类的简化版本，命名为 String 。
 * 你的类应该至少有一个默认构造函数和一个接受 C 风格字符串指针参数的构造函数。
 * 使用 allocator 为你的 String 类分配所需内存。
 */

#ifndef _QUIZ_13_44_HPP_
#define _QUIZ_13_44_HPP_

#include <cstddef>
#include <memory>
#include <utility>

class String
{
  public:
    using size_type = std::size_t;

  private:
    char *elements;
    char *end;
    std::allocator<char> alloc;

    std::pair<char *, char *> alloc_n_copy(const char *, const char *);
    void free();
    void range_initializer(const char *, const char *);

  public:
    // 默认构造函数
    String() : elements(nullptr), end(nullptr)
    {
    }
    String(const char *);
    // 拷贝构造函数
    String(const String &);
    // 析构函数
    ~String();
    // 拷贝赋值运算符
    String &operator=(const String &);

    const char *c_str() const;
    size_type size() const;
    size_type length() const;
};

#endif
