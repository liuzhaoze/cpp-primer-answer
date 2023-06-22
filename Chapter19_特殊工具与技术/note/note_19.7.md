# 19.7 局部类

> 本章术语：
>
> * 局部类（local class）：定义在函数内部的类

局部类的成员必须完整定义在类的内部。

局部类中不允许声明静态数据成员。

局部类只能访问外层作用域定义的类型名、静态变量以及枚举成员，无法访问函数作用域中的其他变量。

```cpp
int a, val;

void foo(int val)
{
    static int si;
    enum Loc { a = 1024, b };

    // 局部类
    struct Bar {
        Loc locVal;            // 正确：局部类型名
        int barVal;

        void fooBar(Loc l = a) // 正确：默认实参为 Loc::a
        {
            barVal = val;      // 错误：局部类无法访问函数作用域中的局部变量
            barVal = ::val;    // 正确：使用全局变量
            barVal = si;       // 正确：使用函数作用域中的静态变量
            barVal = b;        // 正确：使用枚举成员
        }
    };
}
```

局部类的嵌套类的定义可以出现在局部类之外，但是必须定义在与局部类相同的作用域中：

```cpp
void foo()
{
    class Bar {
    public:
        class Nested; // 局部类 Bar 中的嵌套类 Nested
    };

    class Bar::Nested {
        // 在局部类外，与局部类所处作用域相同的作用域中定义嵌套类
    };
}
```

局部类内的嵌套类也是局部类，所以嵌套类的所有成员都必须定义在嵌套类内部。
