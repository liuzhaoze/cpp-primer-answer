#include "Blob.hpp"
#include <initializer_list>
#include <memory>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

template <typename T> void Blob<T>::check(Blob<T>::size_type i, const std::string &msg) const
{
    if (i >= data->size())
    {
        throw std::out_of_range(msg);
    }
}

template <typename T> Blob<T>::Blob() : data(std::make_shared<std::vector<T>>())
{
}

template <typename T> Blob<T>::Blob(std::initializer_list<T> il) : data(std::make_shared<std::vector<T>>(il))
{
}

template <typename T>    // 类的类型参数
template <typename Iter> // 构造函数的类型参数
Blob<T>::Blob(Iter b, Iter e) : data(std::make_shared<std::vector<T>>(b, e))
{
}

template <typename T> typename Blob<T>::size_type Blob<T>::size() const
{
    return data->size();
}

template <typename T> bool Blob<T>::empty() const
{
    return data->empty();
}

template <typename T> void Blob<T>::push_back(const T &t)
{
    data->push_back(t);
}

template <typename T> void Blob<T>::push_back(T &&t)
{
    data->push_back(std::move(t));
}

template <typename T> void Blob<T>::pop_back()
{
    check(0, "pop_back on empty Blob");
    data->pop_back();
}

template <typename T> T &Blob<T>::front()
{
    check(0, "front on empty Blob");
    return data->front();
}

template <typename T> const T &Blob<T>::front() const
{
    check(0, "front on empty Blob");
    return data->front();
}

template <typename T> T &Blob<T>::back()
{
    check(0, "back on empty Blob");
    return data->back();
}

template <typename T> const T &Blob<T>::back() const
{
    check(0, "back on empty Blob");
    return data->back();
}

template <typename T> T &Blob<T>::operator[](Blob<T>::size_type i)
{
    check(i, "subscript out of range");
    return (*data)[i];
}

template <typename T> const T &Blob<T>::operator[](Blob<T>::size_type i) const
{
    check(i, "subscript out of range");
    return (*data)[i];
}

template <typename T> bool operator==(const Blob<T> &lhs, const Blob<T> &rhs)
{
    return *lhs.data == *rhs.data;
}

template <typename T> bool operator!=(const Blob<T> &lhs, const Blob<T> &rhs)
{
    return !(lhs == rhs);
}

template <typename T> std::shared_ptr<std::vector<T>> BlobPtr<T>::check(std::size_t i, const std::string &msg) const
{
    auto ret = wptr.lock();

    if (!ret)
    {
        // wptr 所指对象不存在
        throw std::runtime_error("unbounded BlobPtr");
    }

    if (i >= ret->size())
    {
        throw std::out_of_range(msg);
    }

    return ret;
}

template <typename T> T &BlobPtr<T>::operator*() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

template <typename T> BlobPtr<T> &BlobPtr<T>::operator++()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

template <typename T> BlobPtr<T> &BlobPtr<T>::operator--()
{
    --curr;
    check(curr, "decrement past begin of BlobPtr");
    return *this;
}

template <typename T> BlobPtr<T> BlobPtr<T>::operator++(int)
{
    BlobPtr ret = *this; // 大括号内是类模板作用域，可以不用加模板实参
    ++*this;
    return ret;
}

template <typename T> BlobPtr<T> BlobPtr<T>::operator--(int)
{
    BlobPtr ret = *this; // 大括号内是类模板作用域，可以不用加模板实参
    --*this;
    return ret;
}
