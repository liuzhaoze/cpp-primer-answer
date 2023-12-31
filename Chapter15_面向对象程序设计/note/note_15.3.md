# 15.3 虚函数

当且仅当使用基类的引用或指针调用一个虚成员函数时会执行动态绑定，直到运行时才能确定调用虚函数的版本。  
被调用的函数是与绑定到指针或引用上的对象的动态类型相匹配的那个版本。  
非指针非引用的普通类型调用虚函数时，不会进行动态绑定，其调用的版本是确定的。

必须为每一个虚函数都提供定义，无论它是否被用到。

一个派生类的函数如果覆盖了某个继承而来的虚函数，则它的**形参类型**和**返回类型**必须与被覆盖的虚函数保持一致。  
例外：当虚函数的返回类型是**基类本身的指针或引用**时，覆盖的函数的返回类型也可以是**派生类自身的指针或引用**。

派生类定义一个函数与基类中的虚函数名字相同，但是形参列表不同，是合法的。它被视为派生类新增的成员函数。

如果派生类定义的函数目的是覆盖基类中的虚函数，则需要使用 `override` 关键字标记派生类中的对应函数。

如果派生类中覆盖基类的虚函数被 `final` 标记，则该派生类作为基类时，该虚函数不允许被覆盖。

```cpp
struct B
{
    virtual void f1(int) const;
    virtual void f2();
    void f3();
};

struct D1 : B
{
    void f1(int) const override; // 正确：覆盖基类函数 f1
    void f2(int) override;       // 错误：与基类函数 f2 的形参列表不匹配
    void f3() override;          // 错误：f3 不是虚函数
    void f4() override;          // 错误：不存在函数 f4
};

struct D2 : B
{
    void f1(int) const final; // 不允许以 D2 为基类的派生类覆盖 f1
};

struct D3 : D2
{
    void f2() override; // 正确：覆盖间接基类的 f2
    void f1(int) const override; // 错误：D2 不允许覆盖 f1
};
```

如果通过基类的引用或指针调用函数，则动态绑定的函数使用的是基类中定义的默认实参，派生类覆盖的默认实参不起作用。

*基类和派生类中虚函数的默认实参应该保持一致。*

当一个派生类的虚函数定义需要调用基类虚函数时，应该使用作用域运算符避免动态绑定，否则会导致递归定义。

```cpp
struct D4 : B
{
    void f2() override
    {
        B *baseP = this;
        this->B::f2(); // 如果不加 B:: ，会执行动态绑定调用 D4::f2 从而出现递归定义
    }
};
```

*通常情况下，只有成员函数（或友元）中的代码才需要使用作用域运算符来回避虚函数的动态绑定机制。*

## 练习

* [练习 15.11](../src/quiz_15.11.md)
* [练习 15.12](../src/quiz_15.12.md)
* [练习 15.13](../src/quiz_15.13.md)
* [练习 15.14](../src/quiz_15.14.md)
