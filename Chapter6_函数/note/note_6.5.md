# 6.5 特殊用途语言特性

> 本章术语：
>  
> * 默认实参（default argument）
> * 内联函数（inline）
> * constexpr 函数（constexpr function）

## 6.5.1 默认实参

```c
typedef string::size sz;
string screen(sz ht = 24, sz wid = 80, char backgrnd = ' ');
```

我们可以为一个或多个形参定义默认值。不过需要注意的是，一旦某个形参被赋予了默认值，它后面的所有形参都必须有默认值。

如果我们想使用默认实参，只要在调用函数时省略该实参就可以了。

函数调用时，实参按位置顺序匹配形参，只能省略尾部的实参。  
因此在设计含有默认实参的函数时，让不怎么使用默认值的形参出现在前面，让经常使用默认值的形参出现在后面。

在给定的作用域中，一个形参只能被赋予一次默认实参。同一函数的后续声明只能为之前没有默认值的形参添加默认实参。

```c
string screen(sz, sz, char = ' ');
string screen(sz, sz, char = '*');     // 错误：重复声明默认值
string screen(sz = 24, sz = 80, char); // 正确：添加默认实参
```

*应该在函数声明中指定默认实参，并将该声明放在合适的头文件中。*

局部变量不能作为默认实参。出现在函数体外的表达式可以作为默认实参。  
在函数调用前更新了表达式的值，那么该表达式对应的默认实参也会更新。

*如果函数含有默认实参，则我们在调用该函数时传入的实参数量可能少于他实际使用的实参数量。*

## 6.5.2 内联函数和 constexpr 函数

将小规模操作定义为函数的好处：

* 阅读和理解函数名比读懂等价的表达式容易
* 函数可以确保行为的统一
* 容易修改计算过程
* 可以被重复利用

使用内联函数可以避免函数调用的开销：在编译时，函数在每个调用点上“内联地”展开。

在函数的返回类型前面加上关键字 `inline` 就可以将它声明成内联函数。

*内联说明只是向编译器发出的一个请求，编译器可以选择忽略这个请求。*

一般来说，内联机制用于优化规模较小、流程直接、频繁调用的函数。很多编译器都**不支持**内联递归函数。

constexpr 函数：指能用于常量表达式的函数。

* 函数的返回类型及所有形参的类型都得是字面值类型
* 函数体中必须有且只有一条 return 语句

允许 constexpr 函数的返回值并非一个常量：

```c
constexpr size_t scale(size_t cnt) { return new_sz() * cnt}
```

如果传入 cnt 的实参是常量表达式，那么 scale 的返回类型也是常量表达式。  
如果传入非常量表达式，则返回值是一个非常量表达式。

*constexpr 函数不一定返回常量表达式。*

*内联函数和 constexpr 函数通常定义在头文件中。*

## 6.5.3 调试帮助

assert 预处理宏：`assert(expr);`  
如果 expr 表达式的值为假（ 0 ），则 assert 输出信息并终止程序的执行。  
如果 expr 表达式的值为真（非 0 ），则 assert 什么也不做。

assert 宏定义在 `cassert` 头文件中。  
我们应该直接使用 `assert` 而不是 `std::assert` ，也不需要为 `assert` 提供 `using` 声明。

*避免定义名为 assert 的变量、函数或者其他实体。*

assert 宏常用于检查“不能发生/非法”的条件。应该仅用于验证那些确实不可能发生的事情。

如果定义了预处理变量 `NDEBUG` 则 assert 什么也不做。默认状态下没有定义 `NDEBUG` ，此时 assert 将执行运行时检查。

除了用于 assert 外，也可以使用 `NDEBUG` 编写自己的条件调试代码：

```c
void print(const int ia[], size_t size)
{
#ifndef NDEBUG
    cerr << __func__ << ": array size is " << size << endl;
#endif

    ...
}
```

`__func__` 是编译器定义的一个局部静态变量，用于存放函数的名字。  
`__FILE__` 存放文件名的字符串字面值。  
`__LINE__` 存放当前行号的整形字面值。  
`__TIME__` 存放文件编译时间的字符串字面值。  
`__DATE__` 存放文件编译日期的字符串字面值。

## 练习

* [练习 6.40](../src/quiz_6.40.md)
* [练习 6.41](../src/quiz_6.41.md)
* [练习 6.42](../src/quiz_6.42.cpp)
* [练习 6.43](../src/quiz_6.43.md)
* [练习 6.44](../src/quiz_6.44.cpp)
* [练习 6.45](../src/quiz_6.45.md)
* [练习 6.46](../src/quiz_6.46.cpp)
* [练习 6.47](../src/quiz_6.47.cpp)
* [练习 6.48](../src/quiz_6.48.md)
