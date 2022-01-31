/**
 * 修改你的 Sales_data 类使其隐藏实现的细节。
 * 你之前编写的关于 Sales_data 操作的程序应该继续使用，
 * 借助类的新定义重新编译该程序，确保其工作正常。
 */

#include "quiz_7.21.hpp"

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
