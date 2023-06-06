# 16.4 可变参数模板

> 本章术语：
>
> * 可变参数模板（variadic template）：接受可变数目参数的函数模板或类模板
> * 参数包（parameter packet）：可变数目的参数
>   * 模板参数包（template parameter packet）：表示零个或多个模板参数
>   * 函数参数包（function parameter packet）：表示零个或多个函数参数

```cpp
template <typename T, typename... Args>
void foo(const T &t, const Args& ... rest);
// Args 是模板参数包
// rest 是函数参数包

template <typename... Args> void g(Args ... args)
{
    sizeof...(Args); // 返回类型参数的数目
    sizeof...(args); // 返回函数参数的数目
}
```

## 16.4.1 编写可变参数函数模板

可变参数函数通常是递归调用的，每次递归调用只处理参数包中的第一个实参。此外，还需要一个非可变参数的函数终止递归。

```cpp
// 非可变参数的函数用于终止递归
template <typename T>
ostream &print(ostream &os, const T &t)
{
    return os << t;
}

// 可变参数的函数
template <typename T, typename... Args>
ostream &print(ostream &os, const T &t, const Args&... rest)
{
    os << t << ", ";           // 处理第一个实参
    return print(os, rest...); // 用剩余实参递归调用 print ，剩余实参的第一个会交给下一层调用处理
}
```

*非可变参数模板比可变参数模板更特例化。*

## 16.4.2 包扩展

包**扩展**（expand）就是将参数包中的元素展开为一个逗号分隔的列表，然后对每个元素应用指定的**模式**（pattern）。

```cpp
template <typename... Args>
ostream &errorMsg(ostream &os, const Args&... rest) // [1]
{
    return print(os, debug_rep(rest)...); // [2]
}
```

[1] 模板参数包扩展：将模式 `const Args &` 应用于模板参数包的每一个元素。展开为：  
`const T1 &, const T2 &, const T3 &, ..., const Tn &`

[2] 函数参数包扩展：将模式 `debug_rep()` 应用于函数参数包的每一个元素。展开为：  
`debug_rep(a1), debug_rep(a2), debug_rep(a3), ..., debug_rep(an)`  
不加模式的包扩展 `rest...` 展开为：`a1, a2, a3, ..., an`

## 16.4.3 转发参数包

要完成实参的转发，需要进行两步：

1. 将要转发的参数定义为模板类型参数的右值引用
2. 将实参转发给目标函数时，必须使用 `std::forward` 来保持实参的原始类型

```cpp
// 将传递给 fun 的全部实参转发给 work
template <typename... Args>
void fun(Args&&... args) // 将模板参数包 Args 扩展为右值引用列表
{
    work(std::forward<Args>(args)...); // 同时扩展模板参数包 Args 和函数参数包 args
    // 等价于 forward<T1>(a1), forward<T2>(a2), ..., forward<Tn>(an)
}
```

## 练习

* [练习 16.51](../src/quiz_16.51.md)
* [练习 16.52](../src/quiz_16.52.cpp)
* [练习 16.53](../src/quiz_16.53.cpp)
* [练习 16.54](../src/quiz_16.54.md)
* [练习 16.55](../src/quiz_16.55.md)
* [练习 16.56](../src/quiz_16.56.cpp)
* [练习 16.57](../src/quiz_16.57.md)
* [练习 16.58](../src/quiz_16.58.md)
* [练习 16.59](../src/quiz_16.59.md)
* [练习 16.60](../src/quiz_16.60.md)
* [练习 16.61](../src/quiz_16.61.hpp)
