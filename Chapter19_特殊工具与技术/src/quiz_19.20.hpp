#ifndef _QUIZ_19_20_HPP_
#define _QUIZ_19_20_HPP_

#include "../../lib/StrBlob.hpp"
#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <ostream>
#include <set>
#include <string>
#include <vector>

class TextQuery
{
  public:
    using line_no = StrBlob::size_type;
    class QueryResult; // 负责输出对应单词及所在的行文本 NOTE: 嵌套类

  private:
    StrBlob file;                                                 // 存储整个文件
    std::map<std::string, std::shared_ptr<std::set<line_no>>> wm; // 储存单词到所在行号集合的映射

  public:
    TextQuery(std::ifstream &); // 构造函数
    QueryResult query(const std::string &) const;
};

class TextQuery::QueryResult
{
    friend std::ostream &print(std::ostream &, const QueryResult &);

  private:
    std::string sought;                       // 查询单词
    std::shared_ptr<std::set<line_no>> lines; // sought 所出现的行号（从 1 开始）
    StrBlob file;                             // 输入文件

  public:
    QueryResult(std::string s, std::shared_ptr<std::set<line_no>> p, StrBlob f) : sought(s), lines(p), file(f)
    {
    } // 构造函数
};

std::ostream &print(std::ostream &, const TextQuery::QueryResult &);

#endif
