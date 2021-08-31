/**
 * 使用 Sales_item.h 编写一个程序，读取一组书籍销售记录，并将每条记录打印在标准输出上
 */

#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item book;

    while (std::cin >> book)
        std::cout << book << std::endl;

    return 0;
}
