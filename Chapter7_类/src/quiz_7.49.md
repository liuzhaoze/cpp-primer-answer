对于 combine 函数的三种不同声明，当我们调用 `i.combine(s)` 时分别发生什么情况？  
其中 i 是一个 Sales_data ，而 s 是一个 string 对象。

(a) `Sales_data &combine(Sales_data);`  
(b) `Sales_data &combine(Sales_data&);`  
(c) `Sales_data &combine(const Sales_data&) const;`

> 答：  
> (a) 正确。  
> (b) 错误：无法将临时对象绑定到非常量引用上。可以绑定到常量引用上。  
> (c) 错误： combine 函数会改变成员变量的值，因此不能将其声明为常量成员函数。
