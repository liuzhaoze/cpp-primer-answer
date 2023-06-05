进行下面的调用会发生什么：

```cpp
template <typename T> f1(T, T);
template <typename T1, typename T2> f2(T1, T2);

int i = 0, j = 42;
int *p1 = &i, *p2 = &j;
const int *cp1 = &i, *cp2 = &j;

f1(p1, p2);   // (a)
f2(p1, p2);   // (b)
f1(cp1, cp2); // (c)
f2(cp1, cp2); // (d)
f1(p1, cp1);  // (e)
f2(p1, cp1);  // (f)
```

> 答：  
> (a) 实例化函数：`f1(int *, int *)`  
> (b) 实例化函数：`f2(int *, int *)`  
> (c) 实例化函数：`f1(const int *, const int *)`  
> (d) 实例化函数：`f2(const int *, const int *)`  
> (e) p1 是指向变量的指针 `int *` ，cp1 是指向常量的指针 `const int *` 两者类型不同，无法实例化 f1  
> (f) 实例化函数：`f2(int *, const int *)`
