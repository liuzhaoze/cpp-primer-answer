对于下面的这些语句，请说明对象被声明成了顶层 const 还是底层 const ？
```c
const int v2 = 0;
int v1 = v2;
int *p1 = &v1, &r1 = v1;
const int *p2 = &v2, *const p3 = &i, &r2 = v2;
```

> 答：  
> v2 是顶层 const  
> p2 是底层 const  
> p3 既有顶层 const 又有底层 const  
> r2 是底层 const
