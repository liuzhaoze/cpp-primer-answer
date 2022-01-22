说明下列每组声明中的第二条语句会产生什么影响，并指出哪些不合法。

(a)  
`int calc(int&, int&);`  
`int calc(const int&, const int&);`

(b)  
`int calc(char*, char*);`  
`int calc(const char*, const char*);`

(a)  
`int calc(char*, char*);`  
`int calc(char* const, char* const);`

> 答：  
> (a) 第一条匹配整型变量的引用，第二条匹配整型常量的引用。  
> (b) 第一条匹配指向字符型变量的指针，第二条匹配指向字符型常量的指针。  
> (c) 非法，两者都匹配指向字符型变量的指针。
