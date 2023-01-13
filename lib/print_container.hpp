#ifndef _PRINT_CONTAINER_HPP_
#define _PRINT_CONTAINER_HPP_

#include <ostream>

template <typename T> std::ostream &print_container(std::ostream &ostrm, T begin, T end)
{
    while (begin != end)
    {
        ostrm << *begin << " ";
        ++begin;
    }

    return ostrm;
}

#endif
