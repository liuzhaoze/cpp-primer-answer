说明下面的这些定义是什么意思，挑出其中不合法的。

(a) `int i, *const cp;`  
(b) `int *p1, *const p2;`  
(c) `const int ic, &r = ic;`  
(d) `const int *const p3;`  
(e) `const int *p;`

> 答：  
> (a) 定义整型对象 i ，定义常量指针 cp （非法，未初始化）。  
> (b) 定义指针对象 p1 ，定义常量指针 p2 （非法，未初始化）。  
> (c) 定义常量对象 ic ，定义常量对象的引用 r 。  
> (d) 定义常量指针 p3 （非法，未初始化）。  
> (e) 定义指向常量的指针 p 。
