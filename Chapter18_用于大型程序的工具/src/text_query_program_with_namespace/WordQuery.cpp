#include "WordQuery.hpp"
#include <iostream>

namespace chapter15
{
chapter10::QueryResult WordQuery::eval(const chapter10::TextQuery &t) const
{
    return t.query(query_word);
}

std::string WordQuery::rep() const
{
#ifdef DEBUG
    std::cout << "WordQuery::rep()" << std::endl;
#endif
    return query_word;
}
} // namespace chapter15
