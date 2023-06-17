#ifndef _NOTQUERY_HPP_
#define _NOTQUERY_HPP_

#include "Query.hpp"
#include "QueryResult.hpp"
#include "Query_base.hpp"
#include "TextQuery.hpp"
#include <iostream>
#include <string>

namespace chapter15
{
class NotQuery : public Query_base
{
    friend Query operator~(const Query &);

  private:
    Query query; // 需要对该 query 进行取反操作

    // 构造函数
    NotQuery(const Query &q) : query(q)
    {
#ifdef DEBUG
        std::cout << "NotQuery(const Query &q)" << std::endl;
#endif
    }

    chapter10::QueryResult eval(const chapter10::TextQuery &) const override;
    std::string rep() const override;
};
} // namespace chapter15

#endif
