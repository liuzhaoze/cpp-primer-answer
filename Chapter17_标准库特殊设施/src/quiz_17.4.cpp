/**
 * 编写并测试你自己版本的 findBook 函数。
 */

#include "../../lib/Sales_data.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <istream>
#include <numeric>
#include <ostream>
#include <string>
#include <tuple>
#include <vector>

// 单个书店的查询结果（书店索引，迭代器范围表示的目标书目销售记录）
using match_t = std::tuple<std::vector<std::vector<Sales_data>>::size_type, std::vector<Sales_data>::const_iterator,
                           std::vector<Sales_data>::const_iterator>;

/**
 * @brief 读入销售记录文件
 *
 * @param file_paths 所有销售记录文件路径
 * @return std::vector<std::vector<Sales_data>> 每个文件储存的销售记录
 */
std::vector<std::vector<Sales_data>> readRecords(std::vector<std::string> file_paths);

/**
 * @brief 返回指定书籍在每家店铺中的查询结果
 *
 * @param files 每个文件储存的销售记录
 * @param book 想要查询的书籍
 * @return std::vector<match_t> 所有查询结果
 */
std::vector<match_t> findBook(const std::vector<std::vector<Sales_data>> &files, const std::string &book);

/**
 * @brief 输出指定书籍的查询结果
 *
 * @param is 读入想要查询的书籍
 * @param os 输出查询结果
 * @param files 每个文件储存的销售记录
 */
void reportResult(std::istream &is, std::ostream &os, const std::vector<std::vector<Sales_data>> &files);

int main()
{
    auto files = readRecords({"../data/store1", "../data/store2", "../data/store3", "../data/store4"});
    reportResult(std::cin, std::cout, files);

    return 0;
}

std::vector<std::vector<Sales_data>> readRecords(std::vector<std::string> file_paths)
{
    std::vector<std::vector<Sales_data>> files;

    for (auto &f_path : file_paths)
    {
        std::ifstream in(f_path);
        std::vector<Sales_data> store; // 该书店的销售记录

        for (Sales_data item; in >> item; store.push_back(item))
            ; // 将文件中的每条销售记录读入 store 中

        std::sort(store.begin(), store.end(), compare_isbn); // 将销售记录按书名排序
        // 排序是必须的，否则无法使用 equal_range 完成二分查找

        files.push_back(store);
    }

    return files;
}

std::vector<match_t> findBook(const std::vector<std::vector<Sales_data>> &files, const std::string &book)
{
    std::vector<match_t> result;

    // 逐一查询每家书店的 book 销售记录
    for (auto iter = files.cbegin(); iter != files.cend(); ++iter)
    {
        auto found = std::equal_range(iter->cbegin(), iter->cend(), book, compare_isbn); // 查找指定书籍的范围

        if (found.first != found.second)
        {
            result.push_back(std::make_tuple(iter - files.cbegin(), found.first, found.second));
        }
    }

    return result;
}

void reportResult(std::istream &is, std::ostream &os, const std::vector<std::vector<Sales_data>> &files)
{
    std::string book; // 要找的书

    while (is >> book)
    {
        auto result = findBook(files, book);

        if (result.empty())
        {
            std::cout << book << " not found in any stores" << std::endl;
            continue;
        }

        for (const auto &store : result)
        {
            os << "store" << std::get<0>(store) + 1
               << " sales: " << std::accumulate(std::get<1>(store), std::get<2>(store), Sales_data(book)) << std::endl;
        }
    }
}
