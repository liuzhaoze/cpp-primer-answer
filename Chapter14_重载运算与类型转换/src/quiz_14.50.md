在初始化 ex1 和 ex2 的过程中，可能用到哪些类类型的转换序列呢？
说明初始化是否正确并解释原因。

```cpp
struct LongDouble {
    LongDouble(double);

    operator double();
    operator float();
};

LongDouble ldObj;
int ex1 = ldObj;
float ex2 = ldObj;
```

> 答：  
> 初始化 `ex1` 错误，出现二义性：ldObj 无法确定应该先转换为 double 还是 float  
> 初始化 `ex2` 正确，ldObj 使用到 float 的类型转换运算符（精确匹配）
