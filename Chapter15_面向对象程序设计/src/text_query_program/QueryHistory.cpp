#include "QueryHistory.hpp"

std::size_t QueryHistory::add_query(const Query &query)
{
    std::shared_ptr<Query> p = std::make_shared<Query>(query);
    query_vec.push_back(p);

    return query_vec.size() - 1;
}

Query &QueryHistory::operator[](std::size_t n)
{
    return *(query_vec[n]);
}
