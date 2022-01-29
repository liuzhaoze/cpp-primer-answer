/**
 * 在你的 Sales_data 类中添加构造函数，然后编写一段程序令其用到每个构造函数。
 */

#include "quiz_7.11.hpp"

int main(int argc, char **argv)
{
    Sales_data s1;                        // 默认初始化
    Sales_data s2("Second book");         // 只提供书名
    Sales_data s3("Third book", 5, 11.1); // 全提供
    Sales_data s4(std::cin);              // 手动输入

    print(std::cout, s1) << std::endl;
    print(std::cout, s2) << std::endl;
    print(std::cout, s3) << std::endl;
    print(std::cout, s4) << std::endl;

    return 0;
}
