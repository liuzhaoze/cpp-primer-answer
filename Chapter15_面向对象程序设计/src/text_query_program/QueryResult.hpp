#ifndef _QUERYRESULT_HPP_
#define _QUERYRESULT_HPP_

// 详细注释见 quiz_12.33

#include "TextQuery.hpp"
#include <iostream>
#include <ostream>
#include <set>

class QueryResult
{
    friend std::ostream &print(std::ostream &, const QueryResult &);
    friend std::ostream &print(std::ostream &, const QueryResult &, TextQuery::line_no, TextQuery::line_no);

  public:
    using ResultIter = std::set<TextQuery::line_no>::iterator;

  private:
    std::string sought;
    std::shared_ptr<std::set<TextQuery::line_no>> lines;
    StrBlob file;

  public:
    QueryResult(std::string s, std::shared_ptr<std::set<TextQuery::line_no>> p, StrBlob f)
        : sought(s), lines(p), file(f)
    {
    }

    ResultIter begin() const;
    ResultIter end() const;
    const StrBlob &get_file() const; // 注意：与 quiz_12.33 中的有所不同
};

std::ostream &print(std::ostream &, const QueryResult &);
std::ostream &print(std::ostream &, const QueryResult &, TextQuery::line_no, TextQuery::line_no);

#endif
