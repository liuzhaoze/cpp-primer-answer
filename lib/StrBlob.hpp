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
};

class StrBlobPtr
{
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
    bool operator!=(const StrBlobPtr &p);
};

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
};

#endif
