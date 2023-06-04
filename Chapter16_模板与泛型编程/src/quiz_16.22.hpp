#ifndef _QUIZ_16_22_HPP_
#define _QUIZ_16_22_HPP_

#include "quiz_16.21.hpp"

#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <ostream>
#include <set>
#include <string>
#include <vector>

// 两个类需要共享访问 vector<string> 和 set<line_no>
class TextQuery;   // 负责构建输入文件和单词到行号的映射
class QueryResult; // 负责输出对应单词及所在的行文本

class TextQuery
{
  public:
    using line_no = std::vector<std::string>::size_type;

  private:
    std::shared_ptr<std::vector<std::string>> file;               // 存储整个文件
    std::map<std::string, std::shared_ptr<std::set<line_no>>> wm; // 储存单词到所在行号集合的映射

  public:
    TextQuery(std::ifstream &); // 构造函数
    QueryResult query(const std::string &) const;
};

class QueryResult
{
    friend std::ostream &print(std::ostream &, const QueryResult &);

  private:
    std::string sought;                                  // 查询单词
    std::shared_ptr<std::set<TextQuery::line_no>> lines; // sought 所出现的行号（从 1 开始）
    std::shared_ptr<std::vector<std::string>> file;      // 输入文件

  public:
    QueryResult(std::string s, std::shared_ptr<std::set<TextQuery::line_no>> p,
                std::shared_ptr<std::vector<std::string>> f)
        : sought(s), lines(p), file(f)
    {
    } // 构造函数
};

std::ostream &print(std::ostream &, const QueryResult &);

#endif
