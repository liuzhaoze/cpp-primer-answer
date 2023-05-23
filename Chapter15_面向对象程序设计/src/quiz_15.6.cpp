/**
 * 将 Quote 和 Bulk_quote 的对象传给 15.2.1 节练习中的 print_total 函数，检查该函数是否正确。
 */

#include "../../lib/Quote.hpp"
#include <iostream>

int main()
{
    Quote q("textbook", 10.60);
    Bulk_quote bq("textbook", 10.60, 10, 0.3);

    print_total(std::cout, q, 12);
    print_total(std::cout, bq, 12);

    return 0;
}
