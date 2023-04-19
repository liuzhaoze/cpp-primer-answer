/**
 * 定义一个变量，通过对 11.2.2 节中的名为 bookstore 的 multiset 调用 begin() 来初始化这个变量。
 * 写出变量的类型，不要使用 auto 或 decltype 。
 */

#include "../../lib/Sales_data.hpp"
#include <set>
#include <string>

int main()
{
    std::multiset<Sales_data, bool (*)(const Sales_data &, const Sales_data &)> bookstore(compare_isbn);

    std::multiset<Sales_data, bool (*)(const Sales_data &, const Sales_data &)>::iterator variable = bookstore.begin();

    return 0;
}
