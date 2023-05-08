#include "quiz_13.44.hpp"
#include <algorithm>
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
