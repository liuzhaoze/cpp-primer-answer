下面那些句子是合法的？
如果有不合法的句子，请说明为什么？

(a) `const int buf;`  
(b) `int cnt = 0;`  
(c) `const int sz = cnt;`  
(d) `++cnt; ++sz;`

> 答：  
> (a) 非法， const 对象必须初始化。  
> (b) 合法。  
> (c) 合法。  
> (d) 前一句合法，后一句非法。 const 对象不能被修改。
