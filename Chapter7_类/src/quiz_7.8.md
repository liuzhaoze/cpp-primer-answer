为什么 read 函数将其 Sales_data 参数定义成普通的引用，
而 print 将其参数定义成常量引用？

> 答：因为 read 需要改变 Sales_data 成员变量的值，
> 而 print 不需要对 Sales_data 进行修改。
