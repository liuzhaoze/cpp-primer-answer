#include "WordQuery.hpp"
#include <iostream>

QueryResult WordQuery::eval(const TextQuery &t) const
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
