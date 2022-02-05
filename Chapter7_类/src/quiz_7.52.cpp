/**
 * 使用 2.6.1 节的 Sales_data 类，解释下面的初始化过程。
 * 如果存在问题，尝试修改它。
 */

#include <string>

struct Sales_data
{
    std::string bookNo;
    unsigned units_sold;
    double revenue;
};

Sales_data item = {"978-0590353403", 25, 15.99};
