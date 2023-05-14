#ifndef _STRING_HPP_
#define _STRING_HPP_

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
    // 移动构造函数
    String(String &&) noexcept;
    // 移动赋值运算符
    String &operator=(String &&) noexcept;

    const char *c_str() const;
    size_type size() const;
    size_type length() const;
};

#endif
