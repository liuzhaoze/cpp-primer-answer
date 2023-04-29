/**
 * 为了能让 StrBlobPtr 使用 const StrBlob ，你觉得应该如何修改？
 * 定义一个名为 ConstStrBlobPtr 的类，使其能够指向 const StrBlob 。
 */

#include "../../lib/StrBlob.hpp"
#include <cstddef>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

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
