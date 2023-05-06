# 13.3 交换操作

> 本章术语：
>
> * 拷贝并交换（copy and swap）

使用涉及重排元素顺序的算法，会调用 swap 函数。

如果一个类定义了自己的 swap ，那么算法会调用类自定义版本的 swap ，否则算法将使用标准库定义的 swap 。

*调用 swap 时应该写作 `swap` ，而不是 `std::swap` ：*

```cpp
// 假设 Foo 类中存在一个 HasPtr 类型的成员 h
// 现在为 Foo 类编写 swap 函数
inline void swap(Foo &lhs, Foo &rhs)
{
    using std::swap;
    swap(lhs.h, rhs.h);
    // 编译器会优先匹配 HasPtr 类中定义的 swap 函数，如果不存在，才会匹配标准库中定义的 std::swap 函数
    // 如果写成 std::swap ，就不会匹配 HasPtr 中定义的 swap 函数
}
```

使用 swap 实现赋值运算符（使用拷贝并交换技术）：

```cpp
HasPtr &HasPtr::operator=(HasPtr rhs) // 注意：用传值方式初始化形参，而非传引用方式
{
    swap(*this, rhs); // rhs 是右侧运算对象的拷贝
    return *this;
    // rhs 对象被销毁，旧对象所占的内存被正确释放
}
```

使用拷贝并交换的赋值运算符天然就是异常安全的，且能够正确处理自赋值。

## 练习

* [练习 13.29](../src/quiz_13.29.md)
* [练习 13.30](../src/quiz_13.30.hpp)
* [练习 13.31](../src/quiz_13.31.cpp)
* [练习 13.32](../src/quiz_13.32.md)
