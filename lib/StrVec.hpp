#ifndef _STRVEC_HPP_
#define _STRVEC_HPP_

#include <cstddef>
#include <initializer_list>
#include <memory>
#include <string>
#include <utility>

class StrVec
{
  public:
    using size_type = std::size_t;

    friend bool operator==(const StrVec &, const StrVec &);
    friend bool operator!=(const StrVec &, const StrVec &);
    friend bool operator<(const StrVec &, const StrVec &);
    friend bool operator>(const StrVec &, const StrVec &);
    friend bool operator<=(const StrVec &, const StrVec &);
    friend bool operator>=(const StrVec &, const StrVec &);

  private:
    std::allocator<std::string> alloc; // 内存分配器
    std::string *elements;             // 指向数组首元素的指针
    std::string *first_free;           // 指向数组第一个空闲元素的指针
    std::string *cap;                  // 指向数组尾后位置的指针

    std::pair<std::string *, std::string *> alloc_n_copy(const std::string *, const std::string *);
    void free();
    void chk_n_alloc();
    void reallocate();
    void range_initialize(const std::string *, const std::string *);

  public:
    // 默认构造函数
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr)
    {
    }
    StrVec(std::initializer_list<std::string>);
    // 拷贝构造函数
    StrVec(const StrVec &);
    // 析构函数
    ~StrVec();
    // 拷贝赋值运算符
    StrVec &operator=(const StrVec &);
    // 移动构造函数
    StrVec(StrVec &&) noexcept;
    // 移动赋值运算符
    StrVec &operator=(StrVec &&) noexcept;
    StrVec &operator=(std::initializer_list<std::string>);

    size_type size() const;
    size_type capacity() const;
    std::string *begin() const;
    std::string *end() const;
    void push_back(const std::string &);

    std::string &operator[](size_type);
    const std::string &operator[](size_type) const;
};

bool operator==(const StrVec &, const StrVec &);
bool operator!=(const StrVec &, const StrVec &);
bool operator<(const StrVec &, const StrVec &);
bool operator>(const StrVec &, const StrVec &);
bool operator<=(const StrVec &, const StrVec &);
bool operator>=(const StrVec &, const StrVec &);

#endif
