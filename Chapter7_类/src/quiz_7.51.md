vector 将其单参数的构造函数定义成 explicit 的，而 string 则不是，你觉得原因何在？

> 答：对于如下函数：  
> `int getSize(const std::vector<int>&);`  
> 如果 vector 的单参数构造函数不是 explicit 的，对于如下调用：  
> `getSize(34);`  
> 34 就会被隐式类型转换为 vector ，使程序晦涩难懂。  
> 而 string 类型是 C++ 用于代替 C 语言中的 const char* 类型的，所以遇到字符串字面量，将其隐式地转换为 string 类型是十分自然的。
