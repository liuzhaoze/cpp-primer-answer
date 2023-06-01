#ifndef _WORDQUERY_HPP_
#define _WORDQUERY_HPP_

#include "QueryResult.hpp"
#include "Query_base.hpp"
#include "TextQuery.hpp"
#include <iostream>
#include <string>

class WordQuery : public Query_base
{
    friend class Query;

  private:
    std::string query_word;

    // 构造函数
    WordQuery(const std::string &s) : query_word(s)
    {
#ifdef DEBUG
        std::cout << "WordQuery(const std::string &s)\twhere s = " << s << std::endl;
#endif
    }

    QueryResult eval(const TextQuery &) const override;
    std::string rep() const override;
};

#endif
