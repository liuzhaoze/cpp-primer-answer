在下述表达式的适当位置加上括号，使得加上括号之后表达式的含义与原来的含义相同。

(a) `sizeof x + y`  
(b) `sizeof p->mem[i]`  
(c) `sizeof a < b`  
(d) `sizeof f()`

> 答：  
> (a) `(sizeof x) + y`  
> (b) `sizeof ((p->mem)[i])`  
> (c) `(sizeof a) < b`  
> (d) `sizeof (f())`
