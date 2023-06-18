假设我们有两个基类 Base1 和 Base 2 ，它们各自定义了一个名为 print 的虚成员和一个虚析构函数。
从这两个基类中我们派生出下面的类，它们都重新定义了 print 函数：

```cpp
class D1 : public Base1 { /* ... */ };
class D2 : public Base2 { /* ... */ };
class MI : public D1, public D2 { /* ... */ };
```

通过下面的指针，指出在每个调用中分别使用了哪个函数：

```cpp
Base1 *pb1 = new MI;
Base2 *pb2 = new MI;
D1    *pd1 = new MI;
D2    *pd2 = new MI;

pb1->print(); // (a)
pd1->print(); // (b)
pd2->print(); // (c)
delete pb2;   // (d)
delete pd1;   // (e)
delete pd2;   // (f)
```

> 答：  
> (a) `MI::print()`  
> (b) `MI::print()`  
> (c) `MI::print()`  
> (d) 从左至右依次调用 MI D2 Base2 D1 Base1 的析构函数  
> (e) 从左至右依次调用 MI D2 Base2 D1 Base1 的析构函数  
> (f) 从左至右依次调用 MI D2 Base2 D1 Base1 的析构函数
