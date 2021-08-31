/**
 * 借助 Sales_item.h 头文件，编译并运行本节给出的书店程序。
 */

#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item total;  // 总交易记录

    // 读入第一条交易记录
    if (std::cin >> total) {
        Sales_item trans;
        // 读入剩余交易记录
        while (std::cin >> trans) {
            if (trans.isbn() == total.isbn()) {
                total += trans;  // 读入的书相同，更新销售额
            }
            else {
                // 读入不同的书，将之前的统计结果输出，然后重新统计
                std::cout << total << std::endl;
                total = trans;
            }
        }

        std::cout << total << std::endl;  // 输出最后一本书的结果
    }
    else {
        // 没有读入合法的数据
        std::cerr << "No data!" << std::endl;
        return -1;
    }

    return 0;
}
