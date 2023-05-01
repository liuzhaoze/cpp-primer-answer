/**
 * 在第 15 章中我们将扩展查询系统，在 QueryResult 类中将会需要一些额外的成员。
 * 添加名为 begin 和 end 的成员，返回一个迭代器，指向一个给定查询返回的行号的 set 中的位置。
 * 再添加一个名为 get_file 的成员，返回一个 shared_ptr ，指向 QueryResult 对象中的文件。
 */

#ifndef _QUIZ_12_33_HPP_
#define _QUIZ_12_33_HPP_

#include "../../lib/StrBlob.hpp"
#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <ostream>
#include <set>
#include <string>
#include <vector>

class TextQuery;   // 负责构建输入文件和单词到行号的映射
class QueryResult; // 负责输出对应单词及所在的行文本

class TextQuery
{
  public:
    using line_no = StrBlob::size_type;

  private:
    StrBlob file;                                                 // 存储整个文件
    std::map<std::string, std::shared_ptr<std::set<line_no>>> wm; // 储存单词到所在行号集合的映射

  public:
    TextQuery(std::ifstream &); // 构造函数
    QueryResult query(const std::string &) const;
};

class QueryResult
{
    friend std::ostream &print(std::ostream &, const QueryResult &);

  public:
    using ResultIter = std::set<TextQuery::line_no>::iterator;

  private:
    std::string sought;                                  // 查询单词
    std::shared_ptr<std::set<TextQuery::line_no>> lines; // sought 所出现的行号（从 1 开始）
    StrBlob file;                                        // 输入文件

  public:
    QueryResult(std::string s, std::shared_ptr<std::set<TextQuery::line_no>> p, StrBlob f)
        : sought(s), lines(p), file(f)
    {
    } // 构造函数

    // 新增成员
    ResultIter begin() const
    {
        return lines->begin();
    }
    ResultIter end() const
    {
        return lines->end();
    }
    std::shared_ptr<StrBlob> get_file() const
    {
        return std::make_shared<StrBlob>(file);
    }
};

std::ostream &print(std::ostream &, const QueryResult &);

#endif
