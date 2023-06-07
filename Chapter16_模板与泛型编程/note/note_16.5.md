# 16.5 模板特例化

> 本章术语：
>
> * 模板特例化（template specialization）：模板的一个独立的定义，模板的一个或多个模板参数被指定为特定的类型
> * 部分特例化（partial specialization）：只有类模板可以部分实例化，只指定部分模板参数，并进行类的定义；用户还需要指定特例化中未指定的模板参数

函数模板特例化的方式：

```cpp
// 可以比较任意类型
template <typename T> int compare(const T &, const T &);

// 一个专门用于比较字符串指针的特例化版本（空尖括号）
template <> int compare(const char* const &p1, const char* const &p2)
{
    return strcmp(p1, p2);
}
```

`const char* const &` 是指向 `const char` 的指针的 `const` 引用。  
T 推断为 `char* const` ，即指向常量字符串的指针。外层 `const T &` 表示该指针是不可修改的引用。

特例化的本质是为模板的一个特殊的实例（当 T 取某个特定类型时的实例）提供了定义。  
该定义与可以比较任意类型的模板相比更特例化。

*为了特例化一个模板，原模板的声明必须在作用域中。而且，在任何使用模板实例的代码之前，特例化版本的声明也必须在作用域中。*

*模板及其特例化版本应该声明在同一个头文件中。所有同名模板的声明应该放在前面，然后是这些模板的特例化版本。*

类模板特例化的方式：

```cpp
// 以类模板 std::hash<typename T> 为例
namespace std { // 向命名空间 std 中添加成员

template <> class hash<Sales_data>
{
    // 当模板参数为 Sales_data 时，hash 类的定义
};

}
```

类模板的特例化不必为所有模板参数提供实参。

类模板的部分特例化本质为模板。

```cpp
// 最原始、最通用的版本
template <typename T> struct remove_reference {
    using type = T;
};

// 部分特例化版本，模板参数的类型是原始模板参数类型的子集
template <typename T> struct remove_reference<T&> { // 参数是左值引用时，使用该特例化版本
    using type = T;
};
template <typename T> struct remove_reference<T&&> { // 参数是右值引用时，使用该特例化版本
    using type = T;
};

int i;
remove_reference<decltype(42)>::type a; // 使用原始版本，T 推断为 int
remove_reference<decltype(i)>::type b;  // 使用左值引用特例化的版本，T 推断为 int
remove_reference<decltype(std::move(i))>::type c; // 使用右值引用特例化的版本，T 推断为 int
```

只特例化类中的特定成员：

```cpp
template <typename T> struct Foo
{
    void Bar()
    {
        // T 取除了 int 以外的类型时执行此代码
    }
};

template <> void Foo<int>::Bar() // 对 Foo<int> 类型的对象调用 Bar 会有特例化的处理
{
    // 只有 T 取 int 时执行此代码
}
```

## 练习

* [练习 16.62](../src/quiz_16.62.cpp)
* [练习 16.63](../src/quiz_16.63.cpp)
* [练习 16.64](../src/quiz_16.64.cpp)
* [练习 16.65](../src/quiz_16.65.cpp)
* [练习 16.66](../src/quiz_16.66.md)
* [练习 16.67](../src/quiz_16.67.md)
