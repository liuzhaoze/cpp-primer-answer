# 19.2 运行时类型识别

> 本章术语：
>
> * 运行时类型识别（run-time type identification, RTTI）：通过两个运算符实现：
>   * dynamic_cast 运算符（dynamic_cast operator）：用于将基类的指针或引用安全地转换成派生类的指针或引用
>   * typeid 运算符（typeid operator）：用于返回表达式的类型

## 19.2.1 dynamic_cast 运算符

dynamic_cast 运算符的使用形式：

```cpp
dynamic_cast<type *>(e)  // e 是有效的指针
dynamic_cast<type &>(e)  // e 是左值
dynamic_cast<type &&>(e) // e 是右值
```

e 的类型必须符合以下 3 个条件中的任意一个：

1. e 的类型是目标 type 的公有派生类
2. e 的类型是目标 type 的公有基类
3. e 的类型就是目标 type 类

如果 e 均不符合上述 3 个条件，则转换失败。转换失败的指针类型返回 0 ，转换失败的引用类型抛出 bad_cast 异常。

指针类型的 dynamic_cast ：

```cpp
if (Derived *pd = dynamic_cast<Derived *>(pb))
{
    // 使用 pd 指向的 Derived 对象
}
else
{
    // 使用 pb 指向的 Base 对象
}
```

*在条件部分使用 dynamic_cast 可以同时完成类型转换和结果检查。*

*对空指针执行 dynamic_cast 得到的是所需类型的空指针。*

引用类型的 dynamic_cast ：

```cpp
try
{
    const Derived &d = dynamic_cast<const Derived &>(b);
    // 使用 b 绑定的 Derived 对象
}
catch (bad_cast)
{
    // 处理引用类型转换失败异常
}
```

## 19.2.2 typeid 运算符

typeid 运算符的使用形式：

```cpp
typeid(e)
```

返回一个常量对象的引用，该对象的类型是 type_info 或 type_info 的公有派生类。

当 e 不属于类类型或者是一个不包含任何虚函数的类时，typeid 的值是静态类型，在编译时确定；当 e 是定义了至少一个虚函数的类的左值时，typeid 的值是动态类型，直到运行时才确定结果。

typeid 的用法：

```cpp
Derived *pd = new Derived;
Base *pb = pd;

// 比较两个指针指向的对象的动态类型是否相同
if (typeid(*pd) == typeid(*pb)) { /* pd 和 pb 指向的对象动态类型相同 */ }

// 比较指针指向的对象是否是想要的动态类型
if (typeid(*pb) == typeid(Derived)) {/* pb 指向的对象的动态类型是 Derived */ }

// typeid 应作用于对象，而非指针
if (typeid(pb) == typeid(Derived)) {} // pb 指针是静态类型，两者始终不相等
```

## 19.2.3 使用 RTTI

在为继承体系中的类实现相等运算符时需要使用 RTTI ：

```cpp
bool operator==(const Base &lhs, const Base &rhs)
{
    // lhs 和 rhs 是继承体系中的不同派生类时判定为不相等
    return typeid(lhs) == typeid(rhs) && lhs.equal(rhs);
}
```

继承体系中的每个类都必须定义自己的 equal 函数，从而实现相同类型的比较：

```cpp
bool Derived::equal(const Base &rhs) const
{
    // 在调用 equal 之前，已经在 operator== 中保证了 rhs 和 lhs 的动态类型相同，所以在类型转换时不会抛出异常
    auto r = dynamic_cast<const Derived &>(rhs);
    // 比较两个 Derived 对象并返回结果
}

bool Base::equal(const Base &rhs) const
{
    // 比较两个 Base 对象并返回结果（基类无需类型转换）
}
```

## 19.2.4 type_info 类

type_info 类定义在 `<typeinfo>` 头文件中。

type_info 的操作：

* `t1 == t2` ：如果 type_info 对象 t1 和 t2 表示同一种类型，返回 true ；否则返回 false
* `t1 != t2` ：如果 type_info 对象 t1 和 t2 表示不同类型，返回 true ；否则返回 false
* `t.name()` ：返回一个 C 风格字符串，表示类型名字的可打印形式。类型名字的生成方式因系统而异
* `t1.before(t2)` ：返回一个 bool 值，表示 t1 是否位于 t2 之前。before 采取的顺序关系依赖于编译器

无法定义或拷贝 type_info 对象，也不能为 type_info 对象赋值。
创建 type_info 对象的唯一途径是使用 typeid 运算符。

## 练习

* [练习 19.3](../src/quiz_19.3.md)
* [练习 19.4](../src/quiz_19.4.md)
* [练习 19.5](../src/quiz_19.5.md)
* [练习 19.6](../src/quiz_19.6.md)
* [练习 19.7](../src/quiz_19.7.md)
* [练习 19.8](../src/quiz_19.8.md)
* [练习 19.9](../src/quiz_19.9.cpp)
* [练习 19.10](../src/quiz_19.10.cpp)
