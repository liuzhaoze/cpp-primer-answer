#include "StrBlob.hpp"
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

/**
 * @brief 检查索引 i 是否超出 vector 的范围
 *
 * @param i
 * @param msg
 * @return std::shared_ptr<std::vector<std::string>>
 */
std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(std::size_t i, const std::string &msg) const
{
    auto ret = wptr.lock();

    if (!ret)
    {
        // wptr 所指对象不存在
        throw std::runtime_error("unbounded StrBlobPtr");
    }

    if (i >= ret->size())
    {
        throw std::out_of_range(msg);
    }

    return ret;
}

/**
 * @brief 对 StrBlobPtr 解引用
 *
 * @return std::string&
 */
std::string &StrBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end"); // 检查当前位置是否超出范围
    return (*p)[curr];
}

/**
 * @brief 前缀递增
 *
 * @return StrBlobPtr&
 */
StrBlobPtr &StrBlobPtr::incr()
{
    check(curr, "increment past end of StrBlobPtr"); // curr 指向尾后位置时不能递增
    ++curr;

    return *this;
}

bool StrBlobPtr::operator!=(const StrBlobPtr &p)
{
    return p.curr != curr;
}

/**
 * @brief 返回指向 StrBlob 的首元素的指针
 *
 * @return StrBlobPtr
 */
StrBlobPtr StrBlob::begin()
{
    return StrBlobPtr(*this);
}

/**
 * @brief 返回指向 StrBlob 的尾后元素的指针
 *
 * @return StrBlobPtr
 */
StrBlobPtr StrBlob::end()
{
    return StrBlobPtr(*this, data->size());
}

/**
 * @brief 拷贝赋值运算符
 *
 * @param rhs
 * @return StrBlob&
 */
StrBlob &StrBlob::operator=(const StrBlob &rhs)
{
    data = std::make_shared<std::vector<std::string>>(*(rhs.data));
    return *this;
}
