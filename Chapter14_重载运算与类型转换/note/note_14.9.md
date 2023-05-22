# 14.9 重载、类型转换与运算符

> 本章术语：
>
> * 类类型转换（class-type conversions）：通过转换构造函数和类型转换运算符定义的类类型转换
> * 用户定义的类型转换（user-defined conversions）：类类型转换的别称
> * 类型转换运算符（conversion operator）：将一个类类型的值转换成其他类型
> * 显式的类型转换运算符（explicit conversion operator）

## 14.9.1 类型转换运算符

类型转换运算符是特殊的成员函数，不能声明返回类型，形参列表为空，并且是 const 的成员函数。

类型转换运算符的形式：  
`operator type() const;`  
其中 `type` 是目标类型，不能是 void ，不能是数组或函数类型，但可以是数组指针或函数指针或引用类型。

例：

```cpp
class SmallInt {
private:
    std::size_t val;

public:
    // 转换构造函数：将 int 型转换为 SmallInt 型
    SmallInt(int i = 0) : val(i) {
        if (i < 0 || i > 255) {
            throw std::out_of_range("Bad SmallInt value");
        }
    }

    // 类型转换运算符：将 SmallInt 型转换为 int 型
    operator int() const {
        return val;
    }
};

SmallInt si = 3.14; // double -> int -> SmallInt
si + 3.14;          // SmallInt -> int -> double
```

*只有在类类型与目标类型之间存在一对一映射关系时才定义类型转换运算符；*  
*否则应该使用多个普通的成员函数来区分不同的转换含义。*

### 隐式类型转换可能产生意外结果，应当定义显式类型转换

```cpp
int i = 42;
cin << i; // 即使输出运算符作用于 cin 也不会报错
```

cin 被隐式转换为 bool 类型，`<<` 会被理解为左移运算符。bool 类型会被提升为 int 型，然后左移 42 位。

为避免隐式类型转换产生的意外结果，可以使用显式的类型转换运算符：

```cpp
explicit operator int() const
{
    return val;
}

SmallInt si = 3;
si + 3; // 错误：SmallInt 不能隐式转换为 int
static_cast<int>(si) + 3; // 正确：显式地调用类型转换运算符将 SmallInt 转换为 int
```

当表达式被用作**条件**时，被定义为显式的类型转换运算符也会隐式地执行：

* `if` 、`while` 和 `do-while` 语句的条件部分
* `for` 语句头的条件表达式
* 逻辑与（`&&`）、或（`||`）、非（`!`）运算符的运算对象
* 条件运算符（`? :`）的条件表达式

*向 bool 的类型转换通常用在条件部分。因此 `operator bool()` 一般定义成 explicit 的。*

## 14.9.2 避免有二义性的类型转换

类型转换出现二义性的两种情况：

1. 两个类提供相同的类型转换：A 类定义了一个接受 B 类的转换构造函数（`B -> A`），同时 B 类定义了一个转换目标是 A 类的类型转换运算符（`B -> A`）
2. 类定义了多个转换规则，而这些转换涉及的类型本身可以通过其他类型转换联系在一起

*不要为类定义相同的类型转换（避免情况 1 ）；最多只定义 1 个与算术类型有关的转换规则（避免情况 2 ）。*

情况 1 示例：

```cpp
struct A;
struct B;

struct A {
    A() = default;
    A(const B &); // 存在一个把 B 类转换为 A 类的转换构造函数
};

struct B {
    operator A() const; // 存在一个把 B 类转换为 A 类的类型转换运算符
};

void f(const A &); // 一个接受 A 类常量引用的函数

B b;
f(b); // 错误：B 类对象到 A 类对象的转换存在二义性
f(A(b)); // 正确：显式使用 A 的转换构造函数完成 B 到 A 的类型转换
f(b.operator A()); // 正确：显式使用 B 的类型转换运算符完成 B 到 A 的类型转换
```

情况 2 示例：

```cpp
struct A {
    // 定义了两个与算术类型有关的转换构造函数
    A(int);
    A(double);

    // 定义了两个与算术类型有关的类型转换运算符
    operator int() const;
    operator double() const;
};
void f(long double); // 接受 long double 类型的函数

A a;
f(a); // 错误：在提升到 long double 前，无法确定 A 类型应该转换为 int 还是 double

long l;
A a(l); // 错误：无法确定 long 型变量应该匹配接受 int 的构造函数还是接受 double 的构造函数
```

避免产生二义性的准则：

* 不要在两个类中定义相同的类型转换：如果 Foo 类有一个接受 Bar 类的构造函数，就不要在 Bar 类中定义转换到 Foo 类的类型转换运算符
* 避免转换到内置算术类型的类型转换：当已经定义了一个转换到算术类型的类型转换时，应当：
  * 不要再定义接受算术类型的重载运算符
  * 不要定义转换到多种算术类型的类型转换
* 除了显式地向 bool 类型的转换之外，应该尽量避免定义类型转换函数，并且尽可能限制“显然正确”的非显式构造函数。

```cpp
struct C {
    C(int); // 接受 int 的构造函数
};

struct D {
    D(int); // 接受 int 的构造函数
};

struct E {
    E(double); // 接受 double 的构造函数
};

void func(const C &);
void func(const D &);

func(10); // 错误：出现二义性，无法确定应该构造 C 类对象还是 D 类对象
func(C(10)); // 正确：消除二义性

void func2(const C &);
void func2(const E &);
func2(10); // 错误：即使 10 与 C 的构造函数精确匹配，E 和 C 的构造函数匹配仍然具有二义性
```

*如果在调用重载函数时，我们需要使用构造函数或者强制类型转换来改变实参的类型，则这通常意味着程序的设计存在不足。*

标准类型转换只有**用户定义的类型转换唯一**时才有用（即：只有 C 的转换构造函数）。  
如果用户定义的类型转换不止一个（即：同时存在 C D E 的转换构造函数），则重载函数的调用具有二义性。

## 14.9.3 函数匹配与重载运算符

对于命名函数，具有相同名字的成员函数和非成员函数不会彼此重载，因为两者的调用语法不同。

对于重载的运算符，其候选函数包括成员函数、普通非成员函数和内置版本的非成员函数。

如果我们对同一个类既提供了转换目标是算术类型的类型转换，也提供了重载的运算符，则将会遇到重载运算符与内置运算符的二义性问题：

```cpp
class SmallInt {
public:
    friend SmallInt operator+(const SmallInt &, const SmallInt &);

private:
    std::size_t val;

public:
    SmallInt(int);
    operator int() const; // 目标是算术类型的类型转换
};

SmallInt s1, s2;
SmallInt s3 = s1 + s2; // 调用重载的运算符 operator+

int i = s3 + 0; // 错误：出现二义性
// 可以将 0 转换为 SmallInt 然后调用重载的运算符
// 也可以将 s3 转换为 int 然后调用内置的加法运算符
```

## 练习

* [练习 14.45](../src/quiz_14.45.md)
* [练习 14.46](../src/quiz_14.46.md)
* [练习 14.47](../src/quiz_14.47.md)
* [练习 14.48](../src/quiz_14.48.md)
* [练习 14.49](../src/quiz_14.49.md)
* [练习 14.50](../src/quiz_14.50.md)
* [练习 14.51](../src/quiz_14.51.md)
* [练习 14.52](../src/quiz_14.52.md)
* [练习 14.53](../src/quiz_14.53.md)
