#ifndef _ANDQUERY_HPP_
#define _ANDQUERY_HPP_

#include "BinaryQuery.hpp"
#include "QueryResult.hpp"
#include "TextQuery.hpp"
#include <iostream>

class AndQuery : public BinaryQuery
{
    friend Query operator&(const Query &, const Query &);

  private:
    // 构造函数
    AndQuery(const Query &left, const Query &right) : BinaryQuery(left, right, "&")
    {
#ifdef DEBUG
        std::cout << "AndQuery(const Query &left, const Query &right)\twhere op = " << opSym << std::endl;
#endif
    }

    QueryResult eval(const TextQuery &) const override;
};

#endif
