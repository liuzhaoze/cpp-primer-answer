你认为应该为 Sales_data 类定义上面两种类型转换运算符吗？
应该把它们声明成 explicit 的吗？为什么？

> 答：我认为不应该定义，因为从 Sales_data 类到 string 或 double 类的含义并不是唯一的，它们具有歧义。  
> 应该声明成 explicit 的，目的是避免隐式类型转换。
