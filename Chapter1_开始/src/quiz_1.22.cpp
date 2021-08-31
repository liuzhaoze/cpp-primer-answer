/**
 * 编写程序，读取多个具有相同 ISBN 的销售记录，输出所有记录的和。
 */

#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item book, sum;

    // 判断读入第一条合法数据
    if (std::cin >> book) {
        sum = book;
        // 读入剩下的数据并累加
        while (std::cin >> book) {
            sum += book;
        }

        // 输出和
        std::cout << sum << std::endl;
    }

    return 0;
}
