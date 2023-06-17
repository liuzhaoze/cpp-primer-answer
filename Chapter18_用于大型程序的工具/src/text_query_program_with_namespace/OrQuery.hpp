#ifndef _ORQUERY_HPP_
#define _ORQUERY_HPP_

#include "BinaryQuery.hpp"
#include "QueryResult.hpp"
#include "TextQuery.hpp"
#include <iostream>

namespace chapter15
{
class OrQuery : public BinaryQuery
{
    friend Query operator|(const Query &, const Query &);

  private:
    // 构造函数
    OrQuery(const Query &left, const Query &right) : BinaryQuery(left, right, "|")
    {
#ifdef DEBUG
        std::cout << "OrQuery(const Query &left, const Query &right)\twhere op = " << opSym << std::endl;
#endif
    }

    chapter10::QueryResult eval(const chapter10::TextQuery &) const override;
};
} // namespace chapter15

#endif
