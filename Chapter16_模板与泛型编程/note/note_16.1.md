# 16.1 定义模板

> 本章术语：
>
> * 函数模板（function template）：以 template 关键字开始的函数定义
> * 模板参数列表（template parameter list）：template 关键字后面的尖括号列表
> * 模板实参（template argument）：在调用模板时绑定到模板参数上
> * 类型参数（type parameter）：模板参数列表中的类型
> * 非类型参数（nontype parameter）：实例化时使用常量表达式替换
> * 类模板（class template）
> * 默认模板实参（default template argument）
> * 成员模板（member template）：一个类中的本身是模板的成员函数
> * 显式实例化（explicit instantiation）

## 16.1.1 函数模板

*在模板定义中，模板参数列表不能为空。*

```cpp
template <typename T>
int compare(const T &v1, const T &v2)
{
    if (v1 < v2) return -1;
    if (v2 < v1) return 1;
    return 0;
}
```

编译器可以通过实参类型推断模板参数，从而实例化一个特定版本的函数：

```cpp
compare(1, 0); // 实例化 int compare(const int &, const int &)

vector<int> vec1{1, 2, 3}, vec2{4, 5, 6};
compare(vec1, vec2); // 实例化 int compare(const vector<int> &, const vector<int> &)
```

每个类型参数之前都必须使用关键字 typename：

```cpp
template <typename T, typename U>
U calc(const T &, const U &);
```

模板参数列表中的非类型参数在实例化时，使用用户提供的或编译器推断的**常量表达式**代替。

```cpp
template <unsigned M, unsigned N> // 非类型参数 M 和 N
int compare(const char (&p1)[M], const char (&p2)[N])
{
    // p1 和 p2 是数组的引用
    return strcmp(p1, p2);
}
```

调用 `compare("hi", "mom")` 时，编译器可以推断形参数组的长度为 3 和 4 ，从而实现接受不同长度的实参数组。

绑定到指针或左值引用的非类型参数的实参必须具有**静态的生存期**。普通的局部变量或动态对象不能作为非类型参数的实参。

对于 `inline` 或 `constexpr` 模板函数，相应的说明符应该放在模板参数列表之后，返回类型之前。

泛型代码的两个重要原则：

1. 模板中的函数参数是 const 的引用（避免实参类型不支持拷贝）
2. 函数体中的条件判断仅使用 `<` 比较运算符（避免实参类型没有定义 `>` 运算符）

*模板程序应该尽量减少对实参类型的要求。*

编译器遇到模板定义时不会生成代码，只有当使用模板时才会生成实例化的特定版本的代码。

类定义和函数声明在头文件中，普通函数和成员函数的定义在源文件中。  
函数模板和类模板成员函数的声明和定义**都要放在头文件中**。

大多数编译错误在模板实例化期间报告。

*保证传递给模板的实参支持模板所要求的操作，以及这些操作在模板中能正确工作，是模板调用者的责任。*

## 16.1.2 类模板

以 [Blob.hpp](../../lib/Blob.hpp) 和 [Blob.cpp](../../lib/Blob.cpp) 为例，Blob 类共享访问同一底层元素。

一个类模板的每个实例都形成一个独立的类。

定义在类模板内的成员函数被隐式声明为内联函数。

定义在类模板外的成员函数需要标明 template 关键字和类模板参数列表：  
`template <typename T> ret-type Blob<T>::member-name(parm-list)`

一个类模板的成员函数，只有当程序用到它时才进行实例化。

在类模板的作用域内，可以直接使用模板名，而不必指定模板实参。  
在类模板的作用域外，需要在模板名后指定模板实参。

如果类模板包含非模板友元，那么友元可以访问所有不同的模板实例。  
如果类模板包含模板友元，那么类模板可以决定所有友元模板实例都能访问自己的成员，或者只有特定的友元模板实例可以访问自己的成员。

例：

```cpp
// 前置声明
template <typename> class Pal1;

// 对于非模板类的友元
class NTC
{
    friend class Pal1<NTC>; // 只有用 NTC 实例化的 Pal1 类能够访问 NTC 类（一对一）
    template <typename> friend class Pal2; // Pal2 的所有实例都能够访问 NTC 类（一对多）无需前置声明
};

// 对于模板类的友元
template <typename T> class TC
{
    friend class Pal1<T>; // 只有模板实参相同的 Pal1 能够访问对应的 TC （一对一）
    template <typename> friend class Pal3; // Pal3 的所有实例都能够访问 TC 的所有实例（多对多）无需前置声明
    friend class C; // 非模板类 C 可以访问 TC 的所有实例（多对一）无需前置声明
};
```

可以令类型参数作为自己的友元：

```cpp
template <typename T> class Bar
{
    friend T;
};

// 类型 T 可以访问 Bar<T> 中的成员
```

* 类类型别名：
  * `using StrBlob = Blob<string>;`
* 模板类型别名：
  * `template <typename T> using twin = pair<T, T>;`
    * `twin<int>` 等价于 `pair<int, int>`
  * `template <typename T> using part_no = pair<T, unsigned>`
    * `part_no<string>` 等价于 `pair<string, unsigned>`

### 类模板的 static 成员

```cpp
template <typename T> class Foo
{
private:
    static std::size_t ctr;

public:
    static std::size_t count() { return ctr; }
};
```

对于类模板的每个实例，都有自己独立的 static 成员：

```cpp
Foo<string> fs1, fs2;   // fs1 和 fs2 共享一个 static 成员
Foo<int> fi1, fi2, fi3; // fi1 fi2 fi3 三个对象共享另一个 static 成员
// Foo<string> 和 Foo<int> 的 static 成员相互独立
```

与普通类的 static 数据成员相同，模板类的 static 数据成员有且仅有一个定义：

```cpp
template <typename T> std::size_t Foo<T>::ctr = 0;
// 静态数据成员的定义与其他非内联函数的定义位于在同一个文件中
```

与普通类的 static 成员函数相同，模板类的 static 成员函数既可以通过对象调用，也可以使用作用域运算符直接调用：

```cpp
Foo<int> fi;

fi.count();        // 通过对象调用
Foo<int>::count(); // 通过作用域运算符调用
```

static 成员函数只有在使用时才会实例化。

## 16.1.3 模板参数

模板参数名的可用范围在其声明之后，模板声明或定义结束之前。

模板参数名会隐藏外层作用域中声明的相同名字。

模板参数名不能在模板定义中重复用作变量名。

```cpp
using A = double;

template <typename A, typename B> void f(A a, B b)
{
    A temp = a; // 模板参数名 A 将外层声明的 A = double 隐藏了
    double B; // 错误：模板参数名不能再用作变量名
}

template <typename T, typename T> // 错误：模板参数名不能重用
```

模板声明必须包含模板参数，声明中的模板参数名可以与定义中的不同：

```cpp
template <typename T> class Blob; // 类模板声明
template <typename T> T calc(const T &, const T &); // 函数模板声明
template <typename U> U calc(const U &, const U &); // 等价函数模板声明

template <typename Type> Type calc(const Type &a, const Type &b)
{
    /* 对 calc 函数模板的定义 */
}
```

*一个文件所需要的所有模板的声明通常一起放置在文件的开始位置，出现于任何使用这些模板的代码之前。*

编译器无法区分：对模板参数使用作用域运算符访问的是类型成员还是 static 数据成员。我们需要使用 `typename` 关键字显式说明类型成员：

```cpp
template <typename T> void Foo(const T &t)
{
    T::size_type // 无法确认 size_type 是 T 类中的类型成员还是 static 数据成员
    typename T::size_type sz = 0; // 需要用 typename 显式说明 size_type 是一个类型
}
```

可以为函数和类模板提供默认模板实参：

```cpp
template <typename T, typename F = less<T>> // F 表示一个可调用对象类，默认是 less<T> 类的一个对象
int compare(const T &v1, const T &v2, F f = F()) // f 的默认对象是由类 F 默认初始化得到的对象
{
    if ( f(v1, v2) ) return -1;
    if ( f(v2, v1) ) return 1;
    return 0;
}

compare(0, 42); // f 是 less<int> 默认初始化的对象
compare(item1, item2, compareIsbn); // f 是 compareIsbn 类型的可调用对象
```

和函数默认实参相同，只有模板参数右侧的所有参数都有默认实参时，它才可以有默认实参。

只要使用类模板就必须在模板名后使用尖括号。如果想要使用默认实参，就在模板名后添加空尖括号：`TemplateName<>`

## 16.1.4 成员模板

成员模板不能是虚函数。

在普通类中定义成员模板：

```cpp
class DebugDelete
{
public:
    template <typename T> void operator()(T *p) const // 接受不同类型指针的调用运算符
    {
        delete p;
    }
};
```

在类模板中定义成员模板：

```cpp
template <typename T> class Blob
{
public:
    template <typename Iter> Blob(Iter b, Iter e); // 接受不同类型迭代器的构造函数
};

template <typename T> template <typename Iter>
Blob<T>::Blob(Iter b, Iter e) : data(std::make_shared<std::vector<T>>(b, e)) { }
```

当我们在类模板外定义一个成员模板时，必须**同时**为类模板和成员模板提供模板参数列表。类模板的参数列表在前，成员自己的模板参数列表在后。

## 16.1.5 控制实例化

模板在使用时才会实例化，这意味着当两个或多个独立编译的源文件使用了相同的模板，并提供了相同的模板参数时，每个文件都会有一个完全相同的实例。

可以通过显式实例化避免重复实例化所形成的冗余代码。  
`extern template declaration;` 是实例化声明，意味着 declaration 代表的类模板或函数模板在其他文件的位置被实例化  
`template declaration;` 是实例化定义，意味着 declaration 代表的类模板或函数模板在本文件中被实例化

extern 声明必须出现在任何使用此实例化版本的代码之前。

实例化声明可以出现多次，但是实例化定义必须出现一次。

```cpp
/* Application.cpp */
extern template class Blob<string>;
extern template int compare(const int &, const int &);

Blob<string> sa1, sa2; // extern 语句说明 Blob<string> 的实例化在其他文件中
Blob<int> a1 = {0, 1, 2, 3, 4}; // class Blob<int> 在本文件中实例化
Blob<int> a2(a1); // Blob<int> 的拷贝构造函数在本文件中实例化

int i = compare(a1[0], a2[0]); // extern 语句说明 compare 函数的实例化在其他文件中
```

```cpp
/* templateBuild.cpp */
template class Blob<string>; // 实例化 Blob<string> 包含的所有成员
template int compare(const int &, const int &); // 实例化了 compare 函数
```

编译时必须将 `Application.o` 和 `templateBuild.o` 链接到一起。

类模板的实例化定义会实例化所有成员。在模板实例化定义中所使用的类型（即尖括号中的类型）必须能用于模板中的所有成员函数。

## 16.1.6 效率与灵活性

shared_ptr 在运行时确定删除器的类型，需要增加额外跳转的开销。

unique_ptr 在编译时确定删除器的类型，在调用删除器时无需跳转。

## 练习

* [练习 16.1](../src/quiz_16.1.md)
* [练习 16.2](../src/quiz_16.2.cpp)
* [练习 16.3](../src/quiz_16.3.cpp)
* [练习 16.4](../src/quiz_16.4.cpp)
* [练习 16.5](../src/quiz_16.5.cpp)
* [练习 16.6](../src/quiz_16.6.cpp)
* [练习 16.7](../src/quiz_16.7.cpp)
* [练习 16.8](../src/quiz_16.8.md)
* [练习 16.9](../src/quiz_16.9.md)
* [练习 16.10](../src/quiz_16.10.md)
* [练习 16.11](../src/quiz_16.11.md)
* [练习 16.12](../src/quiz_16.12.md)
* [练习 16.13](../src/quiz_16.13.md)
* [练习 16.14](../src/quiz_16.14.cpp)
* [练习 16.15](../src/quiz_16.15.md)
* [练习 16.16](../src/quiz_16.16.md)
* [练习 16.17](../src/quiz_16.17.md)
* [练习 16.18](../src/quiz_16.18.md)
* [练习 16.19](../src/quiz_16.19.cpp)
* [练习 16.20](../src/quiz_16.20.cpp)
* [练习 16.21](../src/quiz_16.21.hpp)
* [练习 16.22](../src/quiz_16.22_main.cpp)
* [练习 16.23](../src/quiz_16.23.md)
* [练习 16.24](../src/quiz_16.24.md)
* [练习 16.25](../src/quiz_16.25.md)
* [练习 16.26](../src/quiz_16.26.md)
* [练习 16.27](../src/quiz_16.27.md)
* [练习 16.28](../src/quiz_16.28.hpp)
* [练习 16.29](../src/quiz_16.29.hpp)
* [练习 16.30](../src/quiz_16.30.cpp)
* [练习 16.31](../src/quiz_16.31.md)
