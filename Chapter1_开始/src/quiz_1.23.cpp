/**
 * 编写程序，读取多条销售记录，并统计每个 ISBN （每本书）有几条销售记录。
 */

#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item currBook, book;

    // 读取第一本书，确保有数据可以处理
    if (std::cin >> currBook) {
        int cnt = 1;  // 当前值计数
        while (std::cin >> book) {
            // 处理下一本书
            if (book.isbn() == currBook.isbn())
                // 下一本书没变
                ++cnt;
            else {
                std::cout << currBook.isbn() << " has "
                          << cnt << " records " << std::endl;
                currBook = book;  // 记住新书
                cnt = 1;  // 重置计数器
            }
        }

        // 输出最后一种书数出现的个数
        std::cout << currBook.isbn() << " has "
                  << cnt << " records " << std::endl;
    }

    return 0;
}
