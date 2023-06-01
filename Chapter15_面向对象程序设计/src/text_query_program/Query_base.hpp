#ifndef _QUERY_BASE_HPP_
#define _QUERY_BASE_HPP_

#include "QueryResult.hpp"
#include "TextQuery.hpp"
#include <string>

// WordQuery NotQuery BinaryQuery 的抽象基类
class Query_base
{
    friend class Query;

  protected:
    using line_no = TextQuery::line_no;

  private:
    // 返回当前 Query 的 QueryResult
    virtual QueryResult eval(const TextQuery &) const = 0;
    // 将当前 Query 转换为一个 string 用于显示
    virtual std::string rep() const = 0;

  protected:
    virtual ~Query_base() = default;
};

#endif
