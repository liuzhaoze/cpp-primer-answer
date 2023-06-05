# 16.2 模板实参推断

> 本章术语：
>
> * 模板实参推断（template argument deduction）：根据函数实参来确定模板实参的过程
> * 显式模板实参（explicit template argument）

## 16.2.1 类型转换与模板类型参数

只有以下 2 中类型转换会应用于函数模板实参到形参的传递中：

1. const 转换：可以将一个非 const 对象的引用（或指针）传递给一个 const 的引用（或指针）形参。
2. 数组或函数指针转换：如果函数形参不是引用类型，则可以对数组或函数类型的实参应用正常的指针转换。一个数组实参可以转换为一个指向其首元素的指针。一个函数实参可以转换为一个该函数类型的指针。

顶层 const 在转换过程中始终被忽略，是否是 const 由形参决定。

如果形参是一个引用，则数组不会转换为指针。

算术转换、派生类向基类的转换以及用户定义的转换，都不能应用于函数模板。

```cpp
template <typename T>
int compare(const T &v1, const T &v2)
{
    if (v1 < v2) return -1;
    if (v2 < v1) return 1;
    return 0;
}
```

上述模板要求两个实参必须类型相同，否则无法实例化。如果要比较 long 和 int 型，需要定义两个类型参数，而不是一个类型参数：

```cpp
template <typename A, typename B> // 两个类型参数
int compare(const A &v1, const B &v2)
{
    if (v1 < v2) return -1;
    if (v2 < v1) return 1;
    return 0;
}
```

如果函数参数类型不是模板参数，则对实参进行正常的类型转换。

## 16.2.2 函数模板显式实参

```cpp
template <typename T1, typename T2, typename T3>
T1 sum(T2, T3);

auto val = sum<long long>(i, l); // long long 是显式模板实参，显式指明返回类型 T1 是 long long，T2 和 T3 根据实参类型推断
```

显式模板实参按从左到右的顺序与对应的模板参数匹配，只有最右边的模板参数可以通过实参推断确定。

```cpp
template <typename T1, typename T2, typename T3>
T3 sum(T2, T1); // 要显式指定 T1 ，就必须要指定 T3 和 T2
```

显式指定模板实参的实例化函数，在参数传递时可以进行正常的类型转换：

```cpp
long l;
compare(l, 1024);       // 错误：long 和 int 类型不同，无法实例化
compare<long>(l, 1024); // 正确：实例化 int compare(long, long) ，1024 转换为 long
compare<int>(l, 1024);  // 正确：实例化 int compare(int, int) ，l 转换为 int
```

## 16.2.3 尾置返回类型与类型转换

```cpp
template <typename Iter>
??? &fcn(Iter b, Iter e)
{
    return *b;
}
```

返回类型应该是 `decltype(*b)` ，但是形参 b 在形参列表中才出现，无法在函数开头的返回类型处使用。所以应该使用尾置返回类型：

```cpp
template <typename Iter>
auto fcn(Iter b, Iter e) -> decltype(*b) // 返回元素的引用
{
    return *b;
}
```

```cpp
template <typename Iter>
auto fcn(Iter b, Iter e) -> typename remove_reference<decltype(*b)>::type // 返回元素的值拷贝
{
    return *b;
}
```

### 类型转换模板

定义在 `<type_traits>` 头文件中：

|`Mod<T>` 中 Mod 为|如果 T 为|那么 `Mod<T>::type` 为
|:-:|:-:|:-:|
|remove_reference|`X&` / `X&&`|`X`|
|add_const|非 `X&` / `const X` / 函数|`const T`|
|add_lvalue_reference|非 `X&`|`T&`|
|remove_pointer|`X*`|`X`|
|add_pointer|`X&` / `X&&` / 其他|`X*` / `T*`|
|make_signed|`unsigned X`|`X`|
|make_unsigned|带符号类型|`unsigned X`|
|remove_extent|`X[n]`|`X`|
|remove_all_extents|`X[n1][n2]...`|`X`|

如果 T 不可能（或不必要）转换为目标类型，那么 type 类型就是模板参数类型 T 本身。

## 16.2.4 函数指针和实参推断

当我们用一个函数模板初始化一个函数指针或为一个函数指针赋值时，编译器使用指针的类型来推断模板实参。

```cpp
template <typename T> int compare(const T &, const T &);

int (*pf1)(const int &, const int &) = compare; // 根据 pf1 的类型实例化 T 为 int 的 compare 版本

// func 有两个接受函数指针的重载版本，一个形参为 string ，一个形参为 int
void func(int(*)(const string &, const string &));
void func(int(*)(const int &, const int &));

func(compare);      // 错误：编译器无法确定 T 到底应该是 string 还是 int
func(compare<int>); // 正确：需要显式指出实例化的版本
```

## 16.2.5 模板实参推断和引用

```cpp
template <typename T> void f1(T &);
f1(i);  // i 是 int ，T 推断为 int
f1(ci); // ci 是 const int ，T 推断为 const int
f1(5);  // 错误：实参必须是左值
```

```cpp
template <typename T> void f2(const T &); // 实参可以是左值，也可以是右值
f2(i);  // i 是 int ，T 推断为 int
f2(ci); // ci 是 const int ，const 已经是形参的一部分，T 推断为 int
f2(5);  // const & 可以绑定到右值，T 推断为 int
```

```cpp
template <typename T> void f3(T &&);
f3(42); // T 推断为 int
f3(i);  // T 推断为 int & ，进行引用折叠
f3(ci); // T 推断为 const int & ，进行引用折叠
```

两个引用绑定例外规则：

1. 当我们将一个左值（如 i ）传递给函数的右值引用参数，且该右值引用指向模板类型参数（如 `T&&` ）时，编译器推断模板类型参数为实参的左值引用类型（i 推断为 `int &` ）。
2. 引用的折叠规则：
   * `X& &` / `X& &&` / `X&& &` 都折叠为 `X&` ：引用的引用、引用的右值引用、右值引用的引用都折叠为普通引用
   * `X&& &&` 折叠为 `X&&` ：右值引用的右值引用折叠为右值引用

上述两个例外规则导致了两个重要结果：

1. 如果一个函数参数是一个指向模板类型参数的右值引用，则它可以被绑定到一个左值
2. 同时，如果实参是一个左值，则推断出的模板实参类型将是一个左值引用，且函数参数将被实例化为一个左值引用参数

*引用折叠只能应用于间接创建的引用的引用，如类型别名或模板参数。*

*如果一个函数参数是指向模板参数类型的右值引用，那么可以传递给它任意类型的实参。如果实参是左值，那么函数参数会被实例化为普通的左值引用。*

因为 `T&&` 中的 T 既可以推断为变量（`f3(42)`），也可以推断为引用（`f3(i)`），所以需要重载函数模板来避免 T 的二义性：

```cpp
template <typename T> void f(T &&);      // 绑定到非 const 右值
template <typename T> void f(const T &); // 绑定到左值或 const 右值
```

## 16.2.6 理解 `std::move`

虽然不能隐式地将一个左值转换为右值引用，但我们可以用 static_cast 显式地将一个左值转换为一个右值引用：`static_cast<string&&>(t)` t 为 `string &` 。

## 16.2.7 转发

如果在函数模板中调用函数时，希望传递的实参属性与传递给函数模板的实参属性保持一致，那么需要使用**指向模板参数类型的右值引用**和 `std::forward` 标准库：

```cpp
template <typename Type> void intermediary(Type &&arg) // 指向模板参数类型的右值引用
{
    finalFcn(std::forward<Type>(arg)); // std::forward 标准库函数
}

intermediary(val);
// 在调用 finalFcn 时使用的实参与 val 的左值/右值属性，是否是 const 属性，保持一致
```

## 练习

* [练习 16.32](../src/quiz_16.32.md)
* [练习 16.33](../src/quiz_16.33.md)
* [练习 16.34](../src/quiz_16.34.md)
* [练习 16.35](../src/quiz_16.35.md)
* [练习 16.36](../src/quiz_16.36.md)
* [练习 16.37](../src/quiz_16.37.cpp)
* [练习 16.38](../src/quiz_16.38.md)
* [练习 16.39](../src/quiz_16.39.cpp)
* [练习 16.40](../src/quiz_16.40.md)
* [练习 16.41](../src/quiz_16.41.cpp)
* [练习 16.42](../src/quiz_16.42.md)
* [练习 16.43](../src/quiz_16.43.md)
* [练习 16.44](../src/quiz_16.44.md)
* [练习 16.45](../src/quiz_16.45.md)
* [练习 16.46](../src/quiz_16.46.md)
* [练习 16.47](../src/quiz_16.47.cpp)
