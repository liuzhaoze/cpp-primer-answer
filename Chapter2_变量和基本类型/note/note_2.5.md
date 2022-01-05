# 2.5 处理类型

> 本章术语：
>  
> * 类型别名（type alias）
> * 别名声明（alias declaration）

## 2.5.1 类型别名

```c
typedef double wages;  // wages 是 double 的同义词
typedef wages base, *p;  // base 是 double 的同义词， p 是 double * 的同义词
using SI = Sales_item;  // SI 是 Sales_item 的同义词
```

## 2.5.2 auto 类型说明符

auto 定义的变量必须有初始值。  
编译器通过初始值来推算变量的类型。

auto 可以在一条语句中声明多个变量，该语句中所有变量的初始基本数据类型必须相同。

编译器以引用对象的类型作为 auto 的类型。

auto 一般会忽略掉顶层 const ，保留底层 const 。

如果希望推断出的 auto 类型是一个顶层 const，需要用
`const auto` 明确指出。

不能为非常量引用 `auto &` 绑定字面值，可以为常量引用 `const auto &` 绑定字面值。

## 2.5.3 decltype 类型指示符

```c
decltype(f()) sum = x;  // sum 的类型就是函数 f 的返回类型
```

如果 decltype 使用的表达式是一个变量，则 decltype 返回该变量的类型（包括顶层 const 和引用在内）。

```c
int i = 42, *p = &i, &r = i;
decltype(r + 0) b;  // 因为 r 是一个引用，所以 decltype(r) 的结果是引用类型。如果想让结果类型是 r 所绑定的类型，可以把 r 作为表达式的一部分，如 r+0
decltype(*p) c;  // 如果表达式的内容是解引用操作，则 decltype 将得到引用类型。所以 decltype(*p) 的结果类型是 int & ，而非 int 。
```

如果 decltype 使用的是一个**不加括号的变量**，则得到的结果就是该变量的类型；如果给变量加上了**一层或多层括号**，编译器就会把它当成是一个表达式。

* `decltype((variable))` （双层括号）的结果永远是引用
* `decltype(variable)` 只有当 variable 本身是引用时才是引用

**赋值**是会产生引用的一类典型表达式，引用的类型是左值的类型。

## 练习

* [练习 2.33](../src/quiz_2.33.cpp)
* [练习 2.34](../src/quiz_2.34.md)
* [练习 2.35](../src/quiz_2.35.cpp)
* [练习 2.36](../src/quiz_2.36.cpp)
* [练习 2.37](../src/quiz_2.36.cpp)
* [练习 2.38](../src/quiz_2.38.cpp)
