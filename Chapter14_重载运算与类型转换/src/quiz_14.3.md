string 和 vector 都定义了重载的 == 以比较各自的对象，假设 svec1 和 svec2 是存放 string 的 vector ，确定在下面的表达式中分别使用了哪个版本的 == ？

(a) `"cobble" == "stone"`  
(b) `svec1[0] == svec2[0]`  
(c) `svec1 == svec2`  
(d) `svec1[0] == "stone"`

> 答：  
> (a) 使用内置指针类型的比较操作，不使用重载函数  
> (b) 使用 string 类重载的 == 运算符  
> (c) 使用 vector 类重载的 == 运算符  
> (d) 使用 string 类重载的 == 运算符
