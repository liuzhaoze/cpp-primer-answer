#ifndef _QUERYHISTORY_HPP_
#define _QUERYHISTORY_HPP_

#include "Query.hpp"
#include <cstddef>
#include <memory>
#include <vector>

class QueryHistory
{
  private:
    std::vector<std::shared_ptr<chapter15::Query>> query_vec;

  public:
    // 返回新加入 Query 的索引号
    std::size_t add_query(const chapter15::Query &);

    chapter15::Query &operator[](std::size_t);
};

#endif
