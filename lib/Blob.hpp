#ifndef _BLOB_HPP_
#define _BLOB_HPP_

#include <cstddef>
#include <initializer_list>
#include <memory>
#include <string>
#include <vector>

template <typename> class Blob;
template <typename> class BlobPtr;

template <typename T> class Blob
{
    friend class BlobPtr<T>; // 只有模板实参相同的 BlobPtr 才能访问 Blob
    friend bool operator==(const Blob<T> &, const Blob<T> &);
    friend bool operator!=(const Blob<T> &, const Blob<T> &);

  public:
    using value_type = T;
    using size_type = typename std::vector<T>::size_type;

  private:
    std::shared_ptr<std::vector<T>> data;

    // 检查索引是否越界
    void check(size_type, const std::string &) const;

  public:
    // 默认构造函数
    Blob();
    // 接受初始化列表的构造函数
    Blob(std::initializer_list<T>);
    // 接受两个迭代器的构造函数
    template <typename Iter> Blob(Iter, Iter);

    size_type size() const;
    bool empty() const;
    void push_back(const T &);
    void push_back(T &&);
    void pop_back();

    T &front();
    const T &front() const;
    T &back();
    const T &back() const;
    T &operator[](size_type);
    const T &operator[](size_type) const;
};

template <typename T> bool operator==(const Blob<T> &, const Blob<T> &);
template <typename T> bool operator!=(const Blob<T> &, const Blob<T> &);

template <typename T> class BlobPtr
{
  private:
    std::weak_ptr<std::vector<T>> wptr;
    std::size_t curr;

    // 检查索引是否越界，不越界就返回底层对象的指针
    std::shared_ptr<std::vector<T>> check(std::size_t, const std::string &) const;

  public:
    BlobPtr() : curr(0)
    {
    }
    BlobPtr(Blob<T> &a, std::size_t sz = 0) : wptr(a.data), curr(sz)
    {
    }

    T &operator*() const;
    BlobPtr &operator++();   // 在类模板作用域内不必指定模板实参 <T>
    BlobPtr &operator--();   // 在类模板作用域内不必指定模板实参 <T>
    BlobPtr operator++(int); // 在类模板作用域内不必指定模板实参 <T>
    BlobPtr operator--(int); // 在类模板作用域内不必指定模板实参 <T>
};

#endif
