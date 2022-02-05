# 7.5 构造函数再探

> 本章术语：
>  
> * 委托构造函数（delegating constructor）
> * 转换构造函数（converting constructor）
> * 聚合类（aggregate class）

## 7.5.1 构造函数初始值列表

如果类中含有 const 或者引用成员：

```c
class ConstRes {
public:
    ConstRef(int ii);

private:
    int i;
    const int ci; // const 成员
    int &ri;      // 引用成员
}
```

则**不能**使用在构造函数中赋值的方法对成员进行初始化：

```c
ConstRef::ConstRef(int ii)
{
    i = ii;  // 正确
    ci = ii; // 错误：不能给 const 赋值
    ri = i;  // 错误： ri 没有被初始化
}
```

**只能**使用构造函数初始值列表初始化引用和 const 成员：

```c
ConstRef::ConstRef(int ii) : i(ii), ci(ii), ri(i) {}
```

*如果成员是 const 、引用，或者属于某种未提供默认构造函数的类类型，我们必须通过构造函数初始值列表为这些成员提供初始值。*

*建议使用构造函数初始值列表对成员进行初始化。*

成员的初始化顺序与他们在**类定义中的出现顺序一致**。构造函数初始值列表中初始值的顺序**不会影响**实际的初始化顺序。

*最好令构造函数初始值的顺序与成员声明的顺序保持一致。并且尽量避免使用某些成员初始化其他成员。*

*如果一个构造函数为所有参数都提供了默认实参，则他实际上也定义了默认构造函数。*

## 7.5.2 委托构造函数

一个委托构造函数使用他所属类的其他构造函数执行他自己的初始化过程，或者说他把他自己的一些（或者全部）职责委托给了其他构造函数。

一个委托构造函数也有一个成员初始值的列表和一个函数体。在委托构造函数内，成员初始值列表只有一个唯一的入口，就是类名本身。和其他成员初始值一样，类名后面紧跟圆括号括起来的参数列表，参数列表必须与类中另外一个构造函数匹配。

```c
class Sales_data
{
public:
    // 非委托构造函数
    Sales_data(std::string s, unsigned cnt, double price) :
        bookNo(s), units_sold(cnt), revenue(cnt * price) {}

    // 委托构造函数
        // 委托给第一个构造函数：
    Sales_data() : Sales_data("", 0, 0) {}
    Sales_data(std::string s) : Sales_data(s, 0, 0) {}
        // 委托给第二个构造函数
    Sales_data(std::istream &is) : Sales_data() { read(is, *this) }
}
```

## 7.5.3 默认构造函数的作用

当对象被默认初始化或值初始化时自动执行默认构造函数。

默认初始化在以下情况下发生：

* 当我们在块作用域内不使用任何初始值定义一个非静态变量或者数组时（2.2.1节）
* 当一个类本身含有类类型的成员且使用合成的默认构造函数时（7.1.4节）
* 当类类型的成员没有在构造函数初始值列表中显式地初始化时（7.1.4节）

值初始化在以下情况下发生：

* 在数组初始化的过程中如果我们提供的初始值数量少于数组的大小时（3.5.1节）
* 当我们不使用初始值定义一个局部静态变量时（6.1.1节）
* 当我们通过书写形如 `T()` 的表达式显式地请求值初始化时，其中 `T` 是类型名

*在实际情况下，如果定义了其他构造函数，那么最好也提供一个默认构造函数。*

## 7.5.4 隐式的类类型转换

如果构造函数只接受一个实参，则他实际上定义了转换为此类类型的隐式转换机制。有时我们把这种构造函数称作转换构造函数。

*能通过一个实参调用的构造函数定义了一条从构造函数的参数类型向类类型隐式转换的规则。*

```c
string null_book = "9-999-99999-9";
item.combine(null_book);
// 编译器根据 null_book 自动创建 Sales_data 对象
```

编译器只允许一步隐式类型转换。

```c
// 错误：无法进行两步隐式类型转换
// (1) "9-999-99999-9" 转换为 string
// (2) string 转换为 Sales_data
item.combine("9-999-99999-9");

// 修改：将其中的一步显式转换即可
item.combine(string("9-999-99999-9"));     // 显式转换 (1)
item.combine(Sales_data("9-999-99999-9")); // 显式转换 (2)
```

阻止只带有一个参数的构造函数定义隐式类型转换：  
在构造函数声明处，最前方加 `explicit` 关键字。

```c
explicit Sales_data(const std::string &s) : bookNo(s) {}
// 此时 string 无法隐式转换为 Sales_data 类
```

* 关键字 `explicit` 只对一个参数的构造函数有效。
* 只能在类内声明构造函数时使用 `explicit` 关键字，在类外部定义时不应该重复。
* `explicit` 构造函数只能用于直接初始化，不能用于拷贝初始化。
* 编译器不会在自动转换的过程中使用 `explicit` 构造函数。

```c
Sales_data item1(null_book);  // 正确： explicit 构造函数用于直接初始化
Sales_data item2 = null_book; // 错误： explicit 构造函数不能用于拷贝初始化
// 因为 null_book 不能隐式类型转换为 Sales_data 类
```

`explicit` 构造函数可以用于显式强制类型转换：

```c
item.combine(Sales_data(null_book));
item.combine(static_cast<Sales_data>(null_book));
```

标准库中含有单参数的构造函数的类：

* 接受单参数 `const char*` 的 string 构造函数（非 explicit）
* 接受容量参数的 vector 构造函数（explicit）

## 7.5.5 聚合类

当一个类满足如下条件时，这个类就是聚合类：

* 所有成员都是 public 的
* 没有定义任何构造函数
* 没有类内初始值
* 没有基类，也没有 virtual 函数

例：

```c
struct Data {
    int ival;
    string s;
};
```

初始化聚合类的数据成员：  
使用一个花括号括起来的成员初始值列表

```c
Data val1 = { 0, "Anna" };
```

初始值的顺序必须与声明的顺序一致。

与初始化数组元素的规则一样，如果初始值列表中的元素个数少于类的成员数量，则靠后的成员被值初始化。初始值列表的元素个数绝对不能超过类的成员数量。

聚合类的缺点：

* 要求类的所有成员都是 public 的
* 要正确初始化每个对象的每个成员，因此初始化过程冗长乏味且容易出错
* 添加或删除一个成员之后，所有的初始化语句都需要更新

## 7.5.6 字面值常量类

数据成员都是字面值类型的聚合类是字面值常量类。  
如果一个类不是聚合类，但符合下述要求，则也是一个字面值常量类：

* 数据成员都必须是字面值类型
* 类必须至少含有一个 constexpr 构造函数
* 如果一个数据成员含有类内初始值，则内置类型成员的初始值必须是一条常量表达式；或者如果成员属于某种类类型，则初始值必须使用成员自己的 constexpr 构造函数
* 类必须使用析构函数的默认定义，该成员负责销毁类的对象

constexpr 构造函数可以声明成 `= default` 的形式。  
否则， constexpr 构造函数体应该是空的。

```c
class Debug
{
public:
    constexpr Debug(bool b = true) : hw(b), io(b), other(b) {}
    constexpr Debug(bool h, bool i, bool o) :
        hw(h), io(i), other(o) {}

    constexpr bool any() { return hw || io || other; }
    void set_io(bool b) { io = b; }
    void set_hw(bool b) { hw = b; }
    void set_other(bool b) { other = b; }

private:
    bool hw;    // 硬件错误
    bool io;    // IO 错误
    bool other; // 其他错误
};
```

constexpr 构造函数必须初始化**所有**数据成员。初始值或者使用 constexpr 构造函数，或者是一条常量表达式。

constexpr 构造函数用于生成 constexpr 对象以及 constexpr 函数的参数或返回类型：

```c
constexpr Debug io_sub(false, true, false); // 生成 constexpr 对象
if (io_sub.any())   // 返回 constexpr （等价于 true）
    cerr << "print appropriate error messages" << endl;

constexpr Debug prod(false);                // 生成 constexpr 对象
if (prod.any())     // 返回 constexpr （等价于 false）
    cerr << "print an error message" << endl;
```

## 练习

* [练习 7.36](../src/quiz_7.36.cpp)
* [练习 7.37](../src/quiz_7.37.cpp)
* [练习 7.38](../src/quiz_7.38.md)
* [练习 7.39](../src/quiz_7.39.md)
* [练习 7.40](../src/quiz_7.40.cpp)
* [练习 7.41](../src/quiz_7.41.hpp)
* [练习 7.42](../src/quiz_7.42.cpp)
* [练习 7.43](../src/quiz_7.43.cpp)
* [练习 7.44](../src/quiz_7.44.md)
* [练习 7.45](../src/quiz_7.45.md)
* [练习 7.46](../src/quiz_7.46.md)
* [练习 7.47](../src/quiz_7.47.md)
* [练习 7.48](../src/quiz_7.48.md)
* [练习 7.49](../src/quiz_7.49.md)
* [练习 7.50](../src/quiz_7.50.hpp)
* [练习 7.51](../src/quiz_7.51.md)
* [练习 7.52](../src/quiz_7.52.cpp)
* [练习 7.53](../src/quiz_7.53.cpp)
* [练习 7.54](../src/quiz_7.54.md)
* [练习 7.55](../src/quiz_7.55.md)
