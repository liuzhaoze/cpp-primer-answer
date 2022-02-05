假定 `Sales_data` 的构造函数不是 `explicit` 的，则下述定义将执行什么样的操作？

```c
string null_isbn("9-999-99999-9");
Sales_data item1(null_isbn);
Sales_data item2("9-999-99999-9");
```

> 答： item1 和 item2 都可以被正常地初始化。

如果 Sales_data 的构造函数是 explicit 的，又会发生什么呢？

> 答： item1 和 item2 都可以被正常地初始化。
