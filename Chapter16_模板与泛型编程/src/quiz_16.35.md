下面调用中哪些是错误的（如果有的话）？
如果调用合法，T 的类型是什么？如果调用不合法，问题何在？

```cpp
template <typename T> T calc(T, int);
template <typename T> T fcn(T, T);

double d; float f; char c;

calc(c, 'c'); // (a)
calc(d, f);   // (b)
fcn(c, 'c');  // (c)
fcn(d, f);    // (d)
```

> 答：  
> (a) 合法，实例化函数 `char calc(char, int)` ，`'c'` 将类型转换为 int  
> (b) 合法，实例化函数 `double calc(double int)` ，float 将类型转换为 int  
> (c) 合法，变量 c 和 `'c'` 都是 char ，实例化函数 `char fcn(char, char)`  
> (d) 不合法，double 和 float 类型不同，函数模板无法实例化
