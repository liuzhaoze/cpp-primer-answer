下面的表达式中将发生什么样的类型转换？
```c
float fval;
double dval;
int ival;
char cval;
```

(a) `if (fval)`  
(b) `dval = fval + ival;`  
(c) `dval + ival * cval;`

> 答：  
> (a) fval 转换成 bool  
> (b) ival 转换成 float 计算结果转换为 double  
> (c) cval 提升为 int 乘积转换成 double
