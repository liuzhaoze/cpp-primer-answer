说明下面这两个类型转换运算符的区别。

```cpp
struct Integral {
    operator const int();
    operator int() const;
};
```

> 答：  
> `operator const int();` 是错误的类型转换运算符声明，会被编译器忽略  
> `operator int() const;` 是正确的类型转换运算符声明，它实现了从 Integral 到 int 的类型转换
