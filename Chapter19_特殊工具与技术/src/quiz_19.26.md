说明下列声明语句的含义并判断它们是否合法：

```cpp
extern "C" int compute(int *, int);
extern "C" double compute(double *, double);
```

> 答：非法。因为 C 语言不支持重载函数，所以不允许声明两个同名但形参列表不同的函数。
