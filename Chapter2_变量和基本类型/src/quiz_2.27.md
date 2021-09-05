下面的哪些初始化是合法的？请说明原因。

(a) `int i = -1, &r = 0;`  
(b) `int *const p2 = &i2;`  
(c) `const int i = -1, &r = 0;`  
(d) `const int *const p3 = &i2;`  
(e) `const int *p1 = &i2;`  
(f) `const int &const r2;`  
(g) `const int i2 = i, &r = i;`

> 答：  
> (a) 非法，非常量引用的初始值必须是对象。  
> (b) 合法，指向对象 i2 的常量指针。  
> (c) 合法， r 是值为 0 的临时变量的引用。  
> (d) 合法， p3 是常量指针，它指向常量 i2 。  
> (e) 合法， p1 是指向常量的指针，它指向 i2 。  
> (f) 非法，引用需要设置初始值。  
> (g) 合法，以 i 的值初始化常量 i2 ，定义 r 是 i 的常量引用。
