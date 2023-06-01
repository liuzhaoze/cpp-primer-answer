#ifndef _QUERY_HPP_
#define _QUERY_HPP_

#include "QueryResult.hpp"
#include "Query_base.hpp"
#include "TextQuery.hpp"
#include "WordQuery.hpp"
#include <iostream>
#include <memory>
#include <ostream>
#include <string>

// 隐藏继承体系的接口类
class Query
{
    friend Query operator~(const Query &);
    friend Query operator&(const Query &, const Query &);
    friend Query operator|(const Query &, const Query &);

  private:
    // 指向特定 query 的智能指针
    std::shared_ptr<Query_base> q;
    // 构造函数：通过指针创建 Query
    Query(std::shared_ptr<Query_base> query) : q(query)
    {
#ifdef DEBUG
        std::cout << "Query(std::shared_ptr<Query_base> query)" << std::endl;
#endif
    }

  public:
    // 构造函数：通过 string 创建指向 WordQuery 的 Query
    Query(const std::string &s) : q(new WordQuery(s))
    {
#ifdef DEBUG
        std::cout << "Query(const std::string &s)\twhere s = " << s << std::endl;
#endif
    }

    // 返回当前 Query 的 QueryResult
    QueryResult eval(const TextQuery &) const;
    // 将当前 Query 转换为一个 string 用于显示
    std::string rep() const;
};

Query operator~(const Query &);
Query operator&(const Query &, const Query &);
Query operator|(const Query &, const Query &);
std::ostream &operator<<(std::ostream &, const Query &);

#endif
