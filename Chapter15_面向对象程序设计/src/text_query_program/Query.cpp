#include "Query.hpp"
#include "AndQuery.hpp"
#include "NotQuery.hpp"
#include "OrQuery.hpp"
#include "Query_base.hpp"
#include <iostream>
#include <memory>

QueryResult Query::eval(const TextQuery &t) const
{
    return q->eval(t);
}

std::string Query::rep() const
{
#ifdef DEBUG
    std::cout << "Query::rep()" << std::endl;
#endif
    return q->rep();
}

Query operator~(const Query &operand)
{
    return std::shared_ptr<Query_base>(new NotQuery(operand));
}

Query operator&(const Query &lhs, const Query &rhs)
{
    return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

Query operator|(const Query &lhs, const Query &rhs)
{
    return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

std::ostream &operator<<(std::ostream &os, const Query &query)
{
    return os << query.rep();
}
