/**
 * 编写程序，读取两个 ISBN 相同的 Sales_item 对象，输出它们的和。
 */

#include <iostream>
#include "Sales_item.h"

int main() 
{
    Sales_item item1, item2;

    std::cin >> item1 >> item2;
    std::cout << item1 + item2 << std::endl;

    return 0;
}
