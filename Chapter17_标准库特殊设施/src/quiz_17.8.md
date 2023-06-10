在本节最后一段代码中，如果我们将 `Sales_data()` 作为第三个参数传递给 accumulate ，会发生什么？

> 答：最后的输出中没有要查书籍的 ISBN 。
>
> 因为 `Sales_data()` 使用默认构造函数创建初始值，而默认构造的 Sales_data 对象的 book_No 成员为空字符串。因此结果只累加了 units_sold 和 revenue ，而 book_No 一直是空字符串。
