# 18.3 多重继承与虚继承

> 本章术语：
>
> * 多重继承（multiple inheritance）：从多个直接基类中产生派生类的能力
> * 虚继承（virtual inheritance）：虚继承声明某个类愿意共享它的基类
> * 虚基类（virtual base class）：共享的基类子对象

## 18.3.1 多重继承

```cpp
class ZooAnimal { };
class Endangered { };

class Bear : public ZooAnimal { }; // 单继承
class Panda : public Bear, public Endangered { }; // 多继承
```

在多重继承关系中，派生类的对象包含有每个基类的子对象。

多重继承的派生类的构造函数需要初始化它的所有直接基类：

```cpp
// 显式初始化所有基类
Panda::Panda(std::string name, bool onExhibit)
    : Bear(name, onExhibit, "Panda"), Endangered(Endangered::critical) { }

// 隐式地使用 Bear 的默认构造函数初始化 Bear 子对象
Panda::Panda()
    : Endangered(Endangered::critical) { }
```

基类的**构造顺序**与派生列表中基类的出现顺序保持一致。  
派生类构造函数初始值列表中基类的**出现顺序无需**与派生列表中基类的出现顺序保持一致。

析构函数的调用顺序正好与构造函数相反。

## 18.3.2 类型转换与多个基类

所有基类的指针或引用都可以直接指向一个派生类对象。

指针和引用的静态类型决定了能够使用哪些成员：在调用成员时，首先检查静态类型中是否定义了该成员，如果定义了，则通过动态绑定调用动态类型对应的成员；否则无法调用。

## 18.3.3 多重继承下的类作用域

在只有一个基类的情况下，派生类的作用域嵌套在直接基类和间接基类的作用域中。
查找过程沿着继承体系自底向上进行，直到找到所需的名字。
派生类的名字将隐藏基类的同名成员。

在多重继承的情况下，相同的查找过程在所有直接基类中同时进行。
如果名字在多个基类中都被找到，则对该名字的使用将具有二义性。

可以通过作用域运算符显式指明要使用的名字在哪个基类中。  
避免潜在的二义性的最好的办法是在派生类中为该函数定义一个新版本：

```cpp
double Panda::max_weight() const
{
    return std::max(ZooAnimal::max_weight(), Endangered::max_weight());
}
```

## 18.3.4 虚继承

istream 和 ostream 都继承自 base_ios 基类，而 iostream 继承了 istream 和 ostream 。  
默认情况下 iostream 对象中会包含两个 base_ios 基类部分，一个属于 istream ，另一个属于 ostream 。两者相互独立。  
为了实现 iostream 对象中 istream 和 ostream 部分共享基类 base_ios 的信息，istream 和 ostream 需要**虚继承** base_ios 对象，base_ios 对象称为**虚基类**。此时 iostream 只包含一个 base_ios 基类部分。

指定虚基类的方式是在派生列表中添加关键字 virtual ：

```cpp
// 关键字 public 和 virtual 的顺序随意
class istream : public virtual base_ios { /* ... */ };
class ostream : virtual public base_ios { /* ... */ };

class iostream : public istream, public ostream { /* ... */ }; // 正常派生
```

派生类同样支持向虚基类的类型转换。

当：

* 类 B 有成员 x
* 类 D1 和 D2 虚继承自 B
* 类 D 多重继承了 D1 和 D2

如果：

1. D1 和 D2 中都没有 x 的定义，则 x 将被解析为 B 的成员，此时不存在二义性，一个 D 的对象只含有 x 的一个实例
2. x 是 B 的成员，同时也是 D1 或 D2 中某一个的成员，则同样没有二义性，派生类 D1/D2 的 x 比虚基类 B 的 x 优先级更高
3. 在 D1 和 D2 中都有 x 的定义，则直接访问 x 将产生二义性问题

解决这种二义性问题最好的方法是在派生类中为成员自定义新的实例。

## 18.3.5 构造函数与虚继承

虚基类由最低层的派生类初始化。  
但是因为继承自虚基类的每个类都有可能成为“最低层的派生类”，所以继承自虚基类的**每个派生类**都必须初始化它的虚基类。

即：istream 、ostream 和 iostream 的构造函数都需要显式初始化 base_ios 虚基类，但是 iostream 对象的 base_ios 部分实际上是由 iostream 初始化的，而非 istream 或 ostream 。

含有虚基类的对象的构造顺序：首先使用提供给最低层派生类构造函数的初始值初始化该对象的**虚基类子部分**，接下来按照直接基类在派生列表中出现的次序依次对其进行初始化。

如果最低层派生类构造函数没有显式初始化虚基类子对象，则调用虚基类的默认构造函数；如果虚基类没有默认构造函数，则代码发生错误。

*虚基类的构造总是先于非虚基类。多个虚基类的构造顺序与它们在派生列表中出现的顺序相同。*  
*销毁的顺序与构造顺序相反。*

## 练习

* [练习 18.21](../src/quiz_18.21.md)
* [练习 18.22](../src/quiz_18.22.md)
* [练习 18.23](../src/quiz_18.23.md)
* [练习 18.24](../src/quiz_18.24.md)
* [练习 18.25](../src/quiz_18.25.md)
* [练习 18.26](../src/quiz_18.26.cpp)
* [练习 18.27](../src/quiz_18.27.cpp)
* [练习 18.28](../src/quiz_18.28.md)
* [练习 18.29](../src/quiz_18.29.md)
* [练习 18.30](../src/quiz_18.30.cpp)
