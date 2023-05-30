/**
 * 定义 Quote 和 Bulk_quote 的拷贝控制成员，令其与合成的版本行为一致。
 * 为这些成员以及其他构造函数添加打印状态的语句，使得我们能够知道正在运行哪个程序。
 * 使用这些类编写程序，预测程序将创建和销毁哪些对象。
 * 重复实验，不断比较你的预测和实际输出结果是否相同，直到预测完全准确再结束。
 */

#include "../../lib/Quote.hpp"
#include <utility>

int main()
{
    Bulk_quote bq1;
    Bulk_quote bq2("ss", 2.05, 12, 0.3);

    bq1 = std::move(bq2);

    return 0;
}

// 创建 bq1：
// Quote:  default constructor
// Disc_quote:     default constructor
// Bulk_quote:     default constructor

// 创建 bq2：
// Quote:  constructor taking 2 parameters
// Disc_quote:     constructor taking 4 parameters
// Bulk_quote:     constructor taking 4 parameters

// 调用 Bulk_quote::operator= 移动赋值运算符，比较两个运算对象时创建的临时 Quote 对象：
// Quote:  copy constructor
// Quote:  copy constructor
// Quote:  destructor
// Quote:  destructor

// 调用 Disc_quote::operator= 移动赋值运算符，比较两个运算对象时创建的临时 Quote 对象：
// Quote:  copy constructor
// Quote:  copy constructor
// Quote:  destructor
// Quote:  destructor

// 调用 Quote::operator= 移动赋值运算符，比较两个运算对象时不需要创建任何对象，所以没有输出

// 调用移动赋值运算符逐层返回时输出的信息：
// Quote:  move operator
// Disc_quote:     move operator
// Bulk_quote:     move operator

// 逐层销毁 bq1 和 bq2 时输出的信息：
// Bulk_quote:     destructor
// Disc_quote:     destructor
// Quote:  destructor
// Bulk_quote:     destructor
// Disc_quote:     destructor
// Quote:  destructor
