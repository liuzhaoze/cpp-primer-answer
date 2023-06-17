#ifndef _BINARYQUERY_HPP_
#define _BINARYQUERY_HPP_

#include "Query.hpp"
#include "Query_base.hpp"
#include <iostream>
#include <string>

namespace chapter15
{
// AndQuery OrQuery 的抽象基类
class BinaryQuery : public Query_base
{
  protected:
    Query lhs;         // 左侧运算对象
    Query rhs;         // 右侧运算对象
    std::string opSym; // 运算符的名字

    // 构造函数
    BinaryQuery(const Query &l, const Query &r, std::string op) : lhs(l), rhs(r), opSym(op)
    {
#ifdef DEBUG
        std::cout << "BinaryQuery(const Query &l, const Query &r, std::string op)\twhere op = " << op << std::endl;
#endif
    }

    std::string rep() const override;
};
} // namespace chapter15

#endif
