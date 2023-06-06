#include "Vec.hpp"
#include <algorithm>
#include <cstddef>
#include <initializer_list>
#include <memory>
#include <string>
#include <utility>

template <typename T> void Vec<T>::range_initialize(const T *b, const T *e)
{
    auto new_data = alloc_n_copy(b, e);
    elements = new_data.first;
    first_free = cap = new_data.second;
}

template <typename T> Vec<T>::Vec(const Vec<T> &s)
{
    range_initialize(s.begin(), s.end());
}

template <typename T> Vec<T>::Vec(Vec<T> &&s) noexcept : elements(s.elements), first_free(s.first_free), cap(s.cap)
{
    s.elements = s.first_free = s.cap = nullptr;
}

template <typename T> Vec<T>::Vec(std::initializer_list<T> il)
{
    range_initialize(il.begin(), il.end());
}

template <typename T> Vec<T>::~Vec()
{
    free();
}

template <typename T> typename Vec<T>::size_type Vec<T>::size() const
{
    return first_free - elements;
}

template <typename T> typename Vec<T>::size_type Vec<T>::capacity() const
{
    return cap - elements;
}

template <typename T> T *Vec<T>::begin() const
{
    return elements;
}

template <typename T> T *Vec<T>::end() const
{
    return first_free;
}

template <typename T> Vec<T> &Vec<T>::operator=(const Vec<T> &rhs)
{
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;

    return *this;
}

template <typename T> Vec<T> &Vec<T>::operator=(Vec<T> &&rhs) noexcept
{
    if (this != &rhs)
    {
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;

        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }

    return *this;
}

template <typename T> Vec<T> &Vec<T>::operator=(std::initializer_list<T> il)
{
    auto data = alloc_n_copy(il.begin(), il.end());
    free();
    elements = data.first;
    first_free = cap = data.second;

    return *this;
}

template <typename T> void Vec<T>::chk_n_alloc()
{
    if (size() == capacity())
    {
        reallocate();
    }
}

/**
 * @brief 分配一块内存空间，将指定范围中的元素拷贝到该内存中
 *
 * @param b
 * @param e
 * @return std::pair<std::string *, std::string *>
 *         first: 指向分配的内存的开始位置
 *         second: 指向最后一个构造元素之后的位置
 */
template <typename T> std::pair<T *, T *> Vec<T>::alloc_n_copy(const T *b, const T *e)
{
    auto data = alloc.allocate(e - b);                  // 分配空间，用于保存给定范围中的元素
    return {data, std::uninitialized_copy(b, e, data)}; // 元素构造并拷贝由 uninitialized_copy 完成
}

template <typename T> void Vec<T>::free()
{
    if (elements) // 检查 elements 是否为 nullptr
    {
        // for (auto p = first_free; p != elements;) // 逆序销毁所有 string 元素
        // {
        //     alloc.destroy(--p);
        // }

        // 使用 for_each 和 lambda 代替 for 循环
        std::for_each(elements, first_free, [this](std::string &s) { alloc.destroy(&s); });
        alloc.deallocate(elements, cap - elements); // 释放先前 alloc 申请的全部内存
    }
}

template <typename T> void Vec<T>::reallocate()
{
    auto new_capacity = size() ? (2 * size()) : 1; // 空 StrVec 分配 1 个元素的空间；否则将空间扩展为原来的 2 倍
    auto new_data = alloc.allocate(new_capacity); // 新内存空间

    auto src = elements; // 指向原 string
    auto dst = new_data; // 指向新 string
    for (decltype(size()) i = 0; i != size(); ++i)
    {
        alloc.construct(dst++, std::move(*(src++))); // 使用 std::move 将原来 string 中的元素移动到新内存中
        // 使用 std::move 可以使用移动构造函数，而非拷贝构造函数，以提高效率
        // 使用 std::move 时，string 管理的内存不会被拷贝，而是将内存控制权交给新构造的 string 对象管理
    }
    free(); // 元素移动完毕，释放内存

    elements = new_data;
    first_free = dst;
    cap = elements + new_capacity;
}

template <typename T> void Vec<T>::push_back(const T &s)
{
    chk_n_alloc();                    // 确保有空间容纳新元素
    alloc.construct(first_free++, s); // 构造新元素
}

template <typename T> template <typename... Args> void Vec<T>::emplace_back(Args &&...args)
{
    chk_n_alloc();
    alloc.construct(first_free++, std::forward<Args>(args)...);
}

template <typename T> bool operator==(const Vec<T> &lhs, const Vec<T> &rhs)
{
    return (lhs.size() == rhs.size() && std::equal(lhs.begin(), lhs.end(), rhs.begin()));
}

template <typename T> bool operator!=(const Vec<T> &lhs, const Vec<T> &rhs)
{
    return !(lhs == rhs);
}

template <typename T> bool operator<(const Vec<T> &lhs, const Vec<T> &rhs)
{
    return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template <typename T> bool operator>(const Vec<T> &lhs, const Vec<T> &rhs)
{
    return rhs < lhs;
}

template <typename T> bool operator<=(const Vec<T> &lhs, const Vec<T> &rhs)
{
    return !(rhs < lhs);
}

template <typename T> bool operator>=(const Vec<T> &lhs, const Vec<T> &rhs)
{
    return !(lhs < rhs);
}

template <typename T> T &Vec<T>::operator[](Vec<T>::size_type n)
{
    return elements[n];
}

template <typename T> const T &Vec<T>::operator[](Vec<T>::size_type n) const
{
    return elements[n];
}
