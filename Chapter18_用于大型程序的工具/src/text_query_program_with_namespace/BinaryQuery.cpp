#include "BinaryQuery.hpp"
#include <iostream>
#include <string>

namespace chapter15
{
std::string BinaryQuery::rep() const
{
#ifdef DEBUG
    std::cout << "BinaryQuery::rep()" << std::endl;
#endif
    return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
}

} // namespace chapter15
