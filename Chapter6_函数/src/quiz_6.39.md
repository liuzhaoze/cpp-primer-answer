说明在下面的每组声明中第二条声明语句是何意义。
如果有非法的声明，请指出来。

(a)

```c
int calc(int, int);
int calc(const int, const int);
```

(b)

```c
int get();
double get();
```

(c)

```c
int *reset(int *);
double *reset(double *);
```

> 答：  
> (a) 合法，函数的重复声明在 C++ 中是合法的。重复定义非法。  
> (b) 非法，不允许两个函数除了返回类型外其他所有的要素都相同。  
> (c) 合法， reset 函数有两个重载。
