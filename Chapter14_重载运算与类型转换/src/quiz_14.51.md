在调用 calc 的过程中，可能用到哪些类型转换序列呢？
说明最佳可行函数是如何被选出来的。

```cpp
struct LongDouble {
    LongDouble(double);

    operator double();
    operator float();
};
void calc(int);
void calc(LongDouble);

double dval;
calc(dval);
```

> 答：最佳可行函数是 `void calc(int);`
>
> 类型转换优先级：
>  
> 1. 精确匹配
> 2. 常量转换
> 3. 类型提升
> 4. 算术或指针转换
> 5. 类类型的转换
>
> double 到 int 是 4 级优先级；double 到 LongDouble 是 5 级优先级。  
> 因此 double 到 int 优先级更高。
