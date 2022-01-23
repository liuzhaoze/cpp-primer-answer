# 6.7 函数指针

函数的类型由他的返回类型和形参类型共同决定，与函数名无关。

想要声明一个可以指向该函数的指针，只需要用指针替换函数名即可：

```c
bool lengthCompare(const string &, const string &);
bool (*pf)(const string &, const string &);
// 如果不写括号， pf 是一个返回值为 bool 指针的函数
```

当我们把函数名作为一个值使用时，该函数自动地转换成指针。  
此外，我们还能直接使用指向函数的指针调用该函数，无须提前解引用指针。

```c
pf = lengthCompare;
bool b = pf("hello", "goodbye");
```

不同函数类型的指针之间不能赋值。

重载函数指针的类型**必须**与重载函数中的某一个**精确匹配**。

函数类型的形参实际上是指向函数的指针。

使用类型别名和 decltype 简化使用函数指针的代码：

```c
// Func1 和 Func2 是函数类型
typedef bool Func1(const string &, const string &);
typedef decltype(lengthCompare) Func2;

// FuncP1 和 FuncP2 是指向函数的指针
typedef bool (*FuncP1)(const string &, const string &);
typedef decltype(lengthCompare) *FuncP2;
```

decltype 返回函数类型，而**不会**将函数类型自动转换成指针类型。

返回指向函数的指针：

```c
using F = int(int*, int);     // F 是函数类型
using PF = int(*)(int*, int); // PF 是指针类型

F *f1(int); // 正确：返回函数类型的指针
PF f1(int); // 正确：返回函数指针
F f1(int);  // 错误：函数不能返回函数类型，能返回指向函数的指针类型

// 使用尾置返回类型的方式声明一个返回函数指针的函数
auto f1(int) -> int(*)(int*, int);
```

将 decltype 用于函数返回函数指针的声明：

```c
string::size_type sumLength(const string &, const string &);
string::size_type largerLength(const string &, const string &);

// getFunc 可以返回 sumLength 或者 largerLength 函数指针
decltype(sumLength) *getFunc(const string &);
```

## 练习

* [练习 6.54](../src/quiz_6.54.cpp)
* [练习 6.55](../src/quiz_6.55.cpp)
* [练习 6.56](../src/quiz_6.56.cpp)
