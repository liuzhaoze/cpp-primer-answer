#ifndef _VEC_HPP_
#define _VEC_HPP_

#include <cstddef>
#include <initializer_list>
#include <memory>
#include <string>
#include <utility>

template <typename T> class Vec
{
  public:
    using size_type = std::size_t;

    friend bool operator==(const Vec<T> &, const Vec<T> &);
    friend bool operator!=(const Vec<T> &, const Vec<T> &);
    friend bool operator<(const Vec<T> &, const Vec<T> &);
    friend bool operator>(const Vec<T> &, const Vec<T> &);
    friend bool operator<=(const Vec<T> &, const Vec<T> &);
    friend bool operator>=(const Vec<T> &, const Vec<T> &);

  private:
    std::allocator<T> alloc; // 内存分配器
    T *elements;             // 指向数组首元素的指针
    T *first_free;           // 指向数组第一个空闲元素的指针
    T *cap;                  // 指向数组尾后位置的指针

    std::pair<T *, T *> alloc_n_copy(const T *, const T *);
    void free();
    void chk_n_alloc();
    void reallocate();
    void range_initialize(const T *, const T *);

  public:
    // 默认构造函数
    Vec() : elements(nullptr), first_free(nullptr), cap(nullptr)
    {
    }
    Vec(std::initializer_list<T>);
    // 拷贝构造函数
    Vec(const Vec &);
    // 析构函数
    ~Vec();
    // 拷贝赋值运算符
    Vec &operator=(const Vec &);
    // 移动构造函数
    Vec(Vec &&) noexcept;
    // 移动赋值运算符
    Vec &operator=(Vec &&) noexcept;
    Vec &operator=(std::initializer_list<T>);

    size_type size() const;
    size_type capacity() const;
    T *begin() const;
    T *end() const;
    void push_back(const T &);

    T &operator[](size_type);
    const T &operator[](size_type) const;
};

template <typename T> bool operator==(const Vec<T> &, const Vec<T> &);
template <typename T> bool operator!=(const Vec<T> &, const Vec<T> &);
template <typename T> bool operator<(const Vec<T> &, const Vec<T> &);
template <typename T> bool operator>(const Vec<T> &, const Vec<T> &);
template <typename T> bool operator<=(const Vec<T> &, const Vec<T> &);
template <typename T> bool operator>=(const Vec<T> &, const Vec<T> &);

#endif
