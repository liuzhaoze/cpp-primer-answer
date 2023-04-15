/**
 * 不使用 decltype 重新定义 bookstore 。
 */

#include "../../lib/Sales_data.hpp"
#include <set>
#include <string>

int main()
{
    using p = bool (*)(const Sales_data &, const Sales_data &);
    std::multiset<Sales_data, p> bookstore(compare_isbn);

    return 0;
}
