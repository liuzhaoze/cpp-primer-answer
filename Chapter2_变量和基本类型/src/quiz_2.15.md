下面的哪个定义是不合法的？为什么？

(a) `int ival = 1.01;`  
(b) `int &rval1 = 1.01;`  
(c) `int &rval2 = ival;`  
(d) `int &rval3;`

> 答：  
> (a) 合法，定义变量并初始化。  
> (b) 非法，引用类型的初始值必须是一个对象，
> 不能与字面值或某个表达式的计算结果绑定在一起。  
> (c) 合法。  
> (d) 非法，引用必须被初始化。
