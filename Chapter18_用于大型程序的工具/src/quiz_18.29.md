已知有如下所示的类继承关系：

```cpp
class Class { ... };
class Base : public Class { ... };
class D1 : virtual public Base { ... };
class D2 : virtual public Base { ... };
class MI : public D1, public D2 { ... };
class Final : public MI, public Class { ... };
```

1. 当作用于一个 Final 对象时，构造函数和析构函数的执行次序分别是什么？  
2. 在一个 Final 对象中有几个 Base 部分？几个 Class 部分？  
3. 下面的哪些赋值运算将造成编译错误？

```cpp
Base  *pb;
Class *pc;
MI    *pmi;
D2    *pd2;

pb = new Class; // (a)
pc = new Final; // (b)
pmi = pb;       // (c)
pd2 = pmi;      // (d)
```

> 答：
>
> 1. 构造函数执行顺序：`{[((Class) Base) D1 D2 MI] Class Final}` ；析构函数执行顺序与构造函数相反（提示：先构造虚基类 Base ，然后构造 MI ，最后是 Class Final）  
> 2. Final 对象中只有 1 个 Base 部分，是 D1 D2 的虚基类；有 2 个 Class 部分，一个在 Base 部分中，另一个是 Final 多重继承得到的
> 3.
>    * (a) 错误：不能用派生类的指针指向基类（注：可以用基类指针指向派生类）  
>    * (b) 错误：Class 基类在 Final 类中具有二义性，无法确定是 MI 的基类还是 Final 的直接基类  
>    * (c) 错误：不能用派生类的指针指向基类（注：可以用基类指针指向派生类）  
>    * (d) 正确：可以用基类指针指向派生类，且基类在派生类的继承树中没有二义性
