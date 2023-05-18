#include "String.hpp"
#include <algorithm>
#include <iostream>
#include <memory>
#include <utility>

void String::range_initializer(const char *b, const char *e)
{
    auto new_str = alloc_n_copy(b, e);
    elements = new_str.first;
    end = new_str.second;
}

String::String(const char *s)
{
    char *s1 = const_cast<char *>(s);
    while (*s1)
    {
        ++s1;
    }
    range_initializer(s, s1);
}

String::String(const String &s)
{
    range_initializer(s.elements, s.end);
    std::cout << "copy constructor is called" << std::endl;
}

String::String(String &&s) noexcept : elements(s.elements), end(s.end)
{
    s.elements = s.end = nullptr;
    std::cout << "move constructor is called" << std::endl;
}

String::~String()
{
    free();
}

String &String::operator=(const String &rhs)
{
    auto new_str = alloc_n_copy(rhs.elements, rhs.end);
    free();
    elements = new_str.first;
    end = new_str.second;
    std::cout << "copy-assignment operator is called" << std::endl;

    return *this;
}

String &String::operator=(String &&rhs) noexcept
{
    if (this != &rhs)
    {
        free();
        elements = rhs.elements;
        end = rhs.end;

        rhs.elements = rhs.end = nullptr;
    }
    std::cout << "move-assignment operator is called" << std::endl;

    return *this;
}

std::pair<char *, char *> String::alloc_n_copy(const char *b, const char *e)
{
    auto str = alloc.allocate(e - b);
    return {str, std::uninitialized_copy(b, e, str)};
}

void String::free()
{
    if (elements)
    {
        std::for_each(elements, end, [this](char &c) { alloc.destroy(&c); });
        alloc.deallocate(elements, end - elements);
    }
}

const char *String::c_str() const
{
    return elements;
}

String::size_type String::size() const
{
    return end - elements;
}

String::size_type String::length() const
{
    return end - elements - 1;
}

char *String::begin_ptr() const
{
    return elements;
}

char *String::end_ptr() const
{
    return end;
}

std::ostream &operator<<(std::ostream &os, const String &s)
{
    os << s.c_str();
    return os;
}

bool operator==(const String &lhs, const String &rhs)
{
    return (lhs.size() == rhs.size() && std::equal(lhs.begin_ptr(), lhs.end_ptr(), rhs.begin_ptr()));
}

bool operator!=(const String &lhs, const String &rhs)
{
    return !(lhs == rhs);
}

bool operator<(const String &lhs, const String &rhs)
{
    return std::lexicographical_compare(lhs.begin_ptr(), lhs.end_ptr(), rhs.begin_ptr(), rhs.end_ptr());
}

bool operator>(const String &lhs, const String &rhs)
{
    return rhs < lhs;
}

bool operator<=(const String &lhs, const String &rhs)
{
    return !(rhs < lhs);
}

bool operator>=(const String &lhs, const String &rhs)
{
    return !(lhs < rhs);
}

char &String::operator[](size_type n)
{
    return elements[n];
}

const char &String::operator[](size_type n) const
{
    return elements[n];
}
