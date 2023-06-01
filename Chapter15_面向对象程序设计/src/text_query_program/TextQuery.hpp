#ifndef _TEXTQUERY_HPP_
#define _TEXTQUERY_HPP_

// 详细注释见 quiz_12.33
// 新增：使用 strip 去除关键字和查询请求的格式

#include "../../../lib/StrBlob.hpp"
#include <map>
#include <set>

class QueryResult;

class TextQuery
{
  public:
    using line_no = StrBlob::size_type;

  private:
    StrBlob file;
    std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;

  public:
    TextQuery(std::ifstream &);
    QueryResult query(const std::string &) const;
};

#endif
