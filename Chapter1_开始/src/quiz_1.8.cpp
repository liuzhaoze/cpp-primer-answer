/**
 * 指出 main 函数中的 4 个语句中，哪些输出语句是合法的（如果有的话）
 * 预测编译这些语句会产生什么样的结果，实际编译这些语句来验证你的答案，改正每个编译错误。
 */

#include <iostream>

int main()
{
    std::cout << "/*";  // 合法
    std::cout << "*/";  // 合法
    // std::cout << /* "*/" */;  // 非法，少一个双引号
    std::cout << /* "*/" /* "/*" */;  // 合法

    return 0;
}
