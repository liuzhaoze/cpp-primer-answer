#ifndef _STRBLOB_HPP_
#define _STRBLOB_HPP_

#include <cstddef>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

class StrBlobPtr;
class ConstStrBlobPtr;

class StrBlob
{
  public:
    using size_type = std::vector<std::string>::size_type;
    friend class StrBlobPtr; // 声明友元类，使其能访问 data 私有成员
    friend class ConstStrBlobPtr;

    friend bool operator==(const StrBlob &, const StrBlob &);
    friend bool operator!=(const StrBlob &, const StrBlob &);
    friend bool operator<(const StrBlob &, const StrBlob &);
    friend bool operator>(const StrBlob &, const StrBlob &);
    friend bool operator<=(const StrBlob &, const StrBlob &);
    friend bool operator>=(const StrBlob &, const StrBlob &);

  private:
    std::shared_ptr<std::vector<std::string>> data; // 多个 StrBlob 对象共享一个 vector

    void check(size_type i, const std::string &msg) const
    {
        if (i >= data->size())
        {
            throw std::out_of_range(msg);
        }
    }

  public:
    StrBlob() : data(std::make_shared<std::vector<std::string>>())
    {
    }
    StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il))
    {
    }
    StrBlob(const StrBlob &sb) : data(std::make_shared<std::vector<std::string>>(*(sb.data)))
    {
    }

    size_type size() const
    {
        return data->size();
    }
    bool empty() const
    {
        return data->empty();
    }

    void push_back(const std::string &t)
    {
        data->push_back(t);
    }
    void push_back(const std::string &&t)
    {
        data->push_back(std::move(t));
    }
    void pop_back()
    {
        check(0, "pop_back on empty StrBlob");
        data->pop_back();
    }

    std::string &front()
    {
        check(0, "front on empty StrBlob");
        return data->front();
    }
    std::string &back()
    {
        check(0, "back on empty StrBlob");
        return data->back();
    }
    const std::string &front() const
    {
        check(0, "front on empty StrBlob");
        return data->front();
    }
    const std::string &back() const
    {
        check(0, "back on empty StrBlob");
        return data->back();
    }

    StrBlobPtr begin();
    StrBlobPtr end();

    StrBlob &operator=(const StrBlob &);
    std::string &operator[](size_type);
    const std::string &operator[](size_type) const;
};

bool operator==(const StrBlob &, const StrBlob &);
bool operator!=(const StrBlob &, const StrBlob &);
bool operator<(const StrBlob &, const StrBlob &);
bool operator>(const StrBlob &, const StrBlob &);
bool operator<=(const StrBlob &, const StrBlob &);
bool operator>=(const StrBlob &, const StrBlob &);

class StrBlobPtr
{
  public:
    friend bool operator==(const StrBlobPtr &, const StrBlobPtr &);
    friend bool operator!=(const StrBlobPtr &, const StrBlobPtr &);
    friend bool operator<(const StrBlobPtr &, const StrBlobPtr &);
    friend bool operator>(const StrBlobPtr &, const StrBlobPtr &);
    friend bool operator<=(const StrBlobPtr &, const StrBlobPtr &);
    friend bool operator>=(const StrBlobPtr &, const StrBlobPtr &);

  private:
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr; // 数组当前的位置

    std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string &) const;

  public:
    StrBlobPtr() : curr(0)
    {
    } // wptr 隐式初始化为空；curr 显式初始化为 0
    StrBlobPtr(StrBlob &a, std::size_t sz = 0) : wptr(a.data), curr(sz)
    {
    } // 因为构造函数接受的是非 const 的 StrBlob 的引用，所以不能绑定到 const StrBlob 上

    std::string &deref() const; // 解引用
    StrBlobPtr &incr();         // 前缀递增
    std::string &operator[](StrBlob::size_type);
    const std::string &operator[](StrBlob::size_type) const;
    StrBlobPtr &operator++();
    StrBlobPtr &operator--();
    StrBlobPtr operator++(int);
    StrBlobPtr operator--(int);
    StrBlobPtr &operator+=(StrBlob::size_type);
    StrBlobPtr &operator-=(StrBlob::size_type);
    std::string &operator*() const;
    std::string *operator->() const;
};

bool operator==(const StrBlobPtr &, const StrBlobPtr &);
bool operator!=(const StrBlobPtr &, const StrBlobPtr &);
bool operator<(const StrBlobPtr &, const StrBlobPtr &);
bool operator>(const StrBlobPtr &, const StrBlobPtr &);
bool operator<=(const StrBlobPtr &, const StrBlobPtr &);
bool operator>=(const StrBlobPtr &, const StrBlobPtr &);
StrBlobPtr operator+(const StrBlobPtr &, StrBlob::size_type);
StrBlobPtr operator-(const StrBlobPtr &, StrBlob::size_type);

class ConstStrBlobPtr
{
  private:
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;
    std::shared_ptr<std::vector<std::string>> check(std::size_t i, const std::string &msg) const
    {
        auto ret = wptr.lock();
        if (!ret)
        {
            throw std::runtime_error("unbound StrBlobPtr");
        }

        if (i >= ret->size())
        {
            throw std::out_of_range(msg);
        }

        return ret;
    }

  public:
    ConstStrBlobPtr() : curr(0)
    {
    }
    ConstStrBlobPtr(const StrBlob &a, std::size_t sz = 0) : wptr(a.data), curr(sz)
    {
    } // 形参要加 const

    const std::string &deref() const // 返回值类型要加 const
    {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }

    ConstStrBlobPtr &incr()
    {
        check(curr, "increment past end of ConstStrBlobPtr");
        ++curr;
        return *this;
    }

    const std::string &operator*() const;
    const std::string *operator->() const;
};

#endif
