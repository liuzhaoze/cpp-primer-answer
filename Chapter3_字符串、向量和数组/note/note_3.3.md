# 3.3 标准库类型 vector

> 本章术语：
>  
> * 容器（container）
> * 类模板（class template）
> * 实例化（instantiation）：编译器根据模板创建类或函数的过程。
> * 值初始化的（value-initialized）：只提供 vector 对象容纳的元素数量而略去初始值。

提供实例化的信息：在模板名字后面跟一对尖括号，在括号内放上信息。

不存在包含引用的 vector ，因为引用不是对象。

## 3.3.1 定义和初始化 vector 对象

```c
vector<T> v1;
vector<T> v2(v1);
vector<T> v2 = v1;
vector<T> v3(n, val);
vector<T> v4(n);
vector<T> v5{a, b, c...};
vector<T> v5 = {a, b, c...};
```

初始化的真实含义依赖于传递初始值时用的是花括号还是圆括号。  
如果用圆括号，提供的值是用来构造（construct） vector 对象的。  
如果用花括号，提供的值用来列表初始化（list initialize） vector 对象。

当初始化时使用了花括号的形式，但是提供的值又不能用来列表初始化，
则考虑用这些值构造 vector 对象。

```c
vector<string> v7{10};  // v7 有 10 个默认初始化的元素
vector<string> v8{10, "hi"};  // v8 有 10 个值为"hi"的元素
```

*建议分清花括号和圆括号。*

## 3.3.2 向 vector 对象中添加元素

如果循环体内部包含有向 vector 对象添加元素的语句，则不能使用范围 for 循环。

*范围 for 语句体内不应改变其所遍历序列的大小。*

## 3.3.3 其他 vector 操作

```c
v.empty()
v.size()
v.push_back(t)
v[n]
v1 = v2
v1 = {a, b, c...}
v1 == v2
v1 != v2
<, <=, >, >=
```

要使用 size_type ，需要首先指定它是由哪种类型定义的。
vector 对象的类型总是包含着元素的类型。

```c
vector<int>::size_type  // 正确
vector::size_type       // 错误
```

如果两个 vector 对象的容量不同，但是在相同位置上的元素值都一样，则元素较少的 vector 对象小于元素较多的 vector 对象；
若元素的值有区别，则 vector 对象的大小关系由第一对相异的元素值的大小关系决定。

**不能用下标形式添加元素**  
vector 对象（以及 string 对象）的下标运算符可用于访问已存在的元素，而不能用于添加元素。

确保下标合法的一种有效手段就是尽可能使用范围 for 语句。

## 练习

* [练习 3.12](../src/quiz_3.12.cpp)
* [练习 3.13](../src/quiz_3.13.cpp)
* [练习 3.14](../src/quiz_3.14.cpp)
* [练习 3.15](../src/quiz_3.15.cpp)
* [练习 3.16](../src/quiz_3.16.cpp)
* [练习 3.17](../src/quiz_3.17.cpp)
* [练习 3.18](../src/quiz_3.18.md)
* [练习 3.19](../src/quiz_3.19.cpp)
* [练习 3.20](../src/quiz_3.20.cpp)
