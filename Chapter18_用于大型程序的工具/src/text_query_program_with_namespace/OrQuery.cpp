#include "OrQuery.hpp"
#include "QueryResult.hpp"
#include <algorithm>
#include <iterator>
#include <memory>
#include <set>

namespace chapter15
{
chapter10::QueryResult OrQuery::eval(const chapter10::TextQuery &t) const
{
    auto left = lhs.eval(t), right = rhs.eval(t);

    // 储存左右两侧查询结果的并集
    auto ret_lines = std::make_shared<std::set<line_no>>();
    std::set_union(left.begin(), left.end(), right.begin(), right.end(), std::inserter(*ret_lines, ret_lines->begin()));

    // 返回查询结果的并集
    return chapter10::QueryResult(rep(), ret_lines, left.get_file());
}
} // namespace chapter15
