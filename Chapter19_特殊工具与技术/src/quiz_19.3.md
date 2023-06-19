已知存在如下的类继承体系，其中每个类分别定义了一个公有的默认构造函数和一个虚析构函数：

```cpp
class A { /* ... */ };
class B : public A { /* ... */ };
class C : public B { /* ... */ };
class D : public B, public A { /* ... */ };
```

下面的哪个 dynamic_cast 将失败？

```cpp
A *pa = new C;
B *pb = dynamic_cast<B *>(pa); // (a)

B *pb = new B;
C *pc = dynamic_cast<C *>(pb); // (b)

A *pa = new D;
B *pb = dynamic_cast<B *>(pa); // (c)
```

> 答：  
> (a) 成功：pa 的动态类型为 C ，包含属于 B 的基类子部分，可以完成动态类型转换  
> (b) 失败：pb 的动态类型为 B ，不包含 C 中的成员，所以不能完成动态类型转换  
> (c) 失败：D 中含有两个 A 的基类子部分，A 类具有二义性，无法将指向 D 的指针转换为指向 A 的指针
