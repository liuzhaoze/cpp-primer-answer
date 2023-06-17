#include "QueryHistory.hpp"

std::size_t QueryHistory::add_query(const chapter15::Query &query)
{
    std::shared_ptr<chapter15::Query> p = std::make_shared<chapter15::Query>(query);
    query_vec.push_back(p);

    return query_vec.size() - 1;
}

chapter15::Query &QueryHistory::operator[](std::size_t n)
{
    return *(query_vec[n]);
}
