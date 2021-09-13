假设有如下的定义，
```c
char cval;   int ival;     unsigned int ui;
float fval;  double dval;  
```
请回答在下面的表达式中发生了隐式类型转换吗？如果有，指出来。

(a) `cval = 'a' + 3;`  
(b) `fval = ui - ival * 1.0;`  
(c) `dval = ui * fval;`  
(d) `cval = ival + fval + dval;`

> 答：  
> (a) 有， 'a' 提升为 int ，加法结果转换为 char 。
> (b) 有， ival 转换为 double ，乘积转换为 unsigned int ，差转换为 float 。
> (c) 有， ui 转换为 float ，乘积转换为 double 。
> (d) 有， ival 转换为 float ，第一个和转换为 double ，第二个和转换为 char 。
