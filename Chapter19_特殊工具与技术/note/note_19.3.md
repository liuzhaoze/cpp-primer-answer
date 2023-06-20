# 19.3 枚举类型

> 本章术语：
>
> * 枚举类型（enumeration）：将一组整型常量组织在一起
> * 枚举成员（enumerator）
> * 限定作用域的枚举类型（scoped enumeration）：需要使用作用域运算符访问枚举成员
> * 不限定作用域的枚举类型（unscoped enumeration）：可以直接访问枚举成员

枚举属于字面值常量类型。

限定作用域的枚举类型：

```cpp
enum class open_modes
{
    input, output, append
};

open_modes om = open_modes::append; // 必须使用作用域运算符
```

不限定作用域的枚举类型：

```cpp
enum color // 不使用 class 关键字
{
    red, yellow, green
};

color c = red; // 无需使用作用域运算符
```

默认情况下，枚举值从 0 开始，依次加 1 ，枚举值不唯一。可以指定枚举成员的枚举值：

```cpp
enum class intTypes
{
    chatTyp = 8, shortTyp = 16, intTyp = 16,
    longTyp = 32, long_longTyp = 64
};
```

枚举类型的使用场景：

* 初始化常量表达式
* 将 enum 作为 switch 语句的表达式，枚举值作为 case 标签
* 将枚举类型作为一个非类型模板形参
* 在类的定义中初始化枚举类型的静态数据成员

不限定作用域的枚举类型的对象或枚举成员可以自动转换成整型，但是限定作用域的枚举类型不会进行隐式转换。

可以为枚举成员的枚举值指定类型：

```cpp
enum intValues : unsigned long long
{
    // 枚举成员的取值都是 unsigned long long 型
};
```
