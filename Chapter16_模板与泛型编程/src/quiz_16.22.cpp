#include "quiz_16.22.hpp"
#include "quiz_16.21.hpp"
#include <fstream>
#include <iostream>
#include <memory>
#include <set>
#include <sstream>
#include <string>
#include <vector>

/**
 * @brief Construct a new Text Query:: Text Query object
 *
 * @param infile
 */
TextQuery::TextQuery(std::ifstream &infile) : file(new std::vector<std::string>, DebugDelete()) // NOTE: modified
{
    std::string line;

    while (std::getline(infile, line))
    {
        file->push_back(line);

        int n = file->size(); // 当前行号
        std::istringstream iss(line);
        std::string word;
        while (iss >> word) // 遍历行中的每一个单词
        {
            auto &exist_lines = wm[word]; // 指向该单词所在行的集合的指针

            if (!exist_lines) // word 第一次出现时，字典将值初始化为空指针
            {
                exist_lines.reset(new std::set<line_no>, DebugDelete()); // 为该指针分配一个 set NOTE: modified
            }
            exist_lines->insert(n); // 将行号插入 set
        }
    }
}

/**
 * @brief 对输入文件进行查询
 *
 * @param sought
 * @return QueryResult
 */
QueryResult TextQuery::query(const std::string &sought) const
{
    static std::shared_ptr<std::set<line_no>> nodata(
        new std::set<line_no>,
        DebugDelete()); // 如果未找到 sought ，则返回一个指向空 set 的指针 NOTE: modified
    auto loc = wm.find(sought);

    if (loc == wm.end())
    {
        return QueryResult(sought, nodata, file);
    }
    else
    {
        return QueryResult(sought, loc->second, file);
    }
}

/**
 * @brief 将查询结果输出
 *
 * @param os
 * @param qr
 * @return std::ostream&
 */
std::ostream &print(std::ostream &os, const QueryResult &qr)
{
    os << "\'" << qr.sought << "\' occurs " << qr.lines->size() << ((qr.lines->size() > 1) ? " times." : " time.")
       << std::endl;

    for (auto num : *(qr.lines))
    {
        os << "\t(line " << num << ") " << (*(qr.file))[num - 1] << std::endl;
    }

    return os;
}
