#include "NotQuery.hpp"
#include "QueryResult.hpp"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <memory>
#include <set>

QueryResult NotQuery::eval(const TextQuery &t) const
{
    auto result = query.eval(t);

    // 行号的全集
    std::set<line_no> all_lines;
    for (line_no i = 1; i <= result.get_file().size(); ++i)
    {
        all_lines.insert(i);
    }
    // 储存查询结果的补集
    auto ret_lines = std::make_shared<std::set<line_no>>();
    std::set_difference(all_lines.begin(), all_lines.end(), result.begin(), result.end(),
                        std::inserter(*ret_lines, ret_lines->begin()));

    return QueryResult(rep(), ret_lines, result.get_file());
}

std::string NotQuery::rep() const
{
#ifdef DEBUG
    std::cout << "NotQuery::rep()" << std::endl;
#endif
    return "~(" + query.rep() + ")";
}
