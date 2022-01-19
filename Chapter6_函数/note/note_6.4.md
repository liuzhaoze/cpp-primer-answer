# 6.4 函数重载

> 本章术语：
>  
> * 重载函数（overloaded）：同一作用域内的几个函数名字相同但形参列表不同。

*main 函数不能重载。*

对于重载的函数来说，他们应该在形参数量或形参类型上有所不同。  
不允许两个函数除了返回类型外其他所有的要素都相同。  
类型别名不能算是新类型。

顶层 const 不能区分形参类型：

```c
Record lookup(Phone);
Record lookup(const Phone); // 两个等价

Record lookup(Phone*);
Record lookup(Phone* const); // 两个等价
```

通过底层 const 区分形参类型：  
如果形参是某种类型的指针或引用，则通过区分其指向的是常量还是变量实现函数重载。

```c
Record lookup(Account&);       // Account 的引用
Record lookup(const Account&); // 常量引用
Record lookup(Account*);       // 指向 Account 的指针
Record lookup(const Account*); // 指向常量的指针
```

当传递一个非常量对象或指向非常量对象的指针时，编译器会优先选用非常量版本的函数。

调用重载函数时的三种可能的结果：

* 最佳匹配（best match）
* 无匹配（no match）
* 二义性调用（ambiguous call）

## 6.4.1 重载与作用域

一旦编译器在当前作用域中找到了所需的名字，编译器就会忽略掉外层作用域中的同名实体。

在 C++ 语言中，名字查找发生在类型检查之前。

## 练习

* [练习 6.39](../src/quiz_6.39.md)
