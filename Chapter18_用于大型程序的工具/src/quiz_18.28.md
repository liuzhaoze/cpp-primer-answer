已知存在如下的继承体系，在 VMI 类的内部哪些继承而来的成员无需前缀限定符就能直接访问？
哪些必须有限定符才能访问？说明你的原因。

```cpp
class Base
{
protected:
    int ival;

public:
    void bar(int);
};

class Derived1 : virtual public Base
{
protected:
    char cval;

public:
    void foo(char);
    void bar(char);
};

class Derived2 : virtual public Base
{
protected:
    int ival;
    char cval;

public:
    void foo(int);
};

class VMI : public Derived1, public Derived2 { };
```

> 答：
>
> * `ival` ：18.3.4 情况 2 ，VMI 使用 Derived2::ival
> * `cval` ：18.3.4 情况 3 ，需要使用作用域运算符指明所属的类
> * `foo` ：18.3.4 情况 3 ，需要使用作用域运算符指明所属的类
> * `bar` ：18.3.4 情况 2 ，VMI 使用 Derived1::bar
