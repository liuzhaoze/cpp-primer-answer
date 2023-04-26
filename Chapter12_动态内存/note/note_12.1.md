# 12.1 动态内存与智能指针

> 本章术语：
>
> * 静态内存：用于保存局部 static 对象、类 static 数据成员以及定义在任何函数之外的变量
> * 栈：用于保存定义在函数内的非 static 对象
> * 堆（heap）/自由空间（free store）：用于保存在程序运行时分配的对象，即动态对象（需要显式销毁）
> * 智能指针（smart pointer）：更安全地管理动态对象，避免内存泄漏和非法访问
> * 引用计数（reference count）
> * 析构函数（destructor）：控制对象销毁时进行的操作
> * 定位 new（placement new）：允许向 new 运算符传递额外的参数
> * 悬空指针（dangling pointer）：指向一块曾经保存数据对象但现在已经无效的内存的指针
> * 删除器（deleter）：能够释放某个动态对象的函数

`new` 运算符：在动态内存中为对象分配空间，并返回一个指向该对象的指针  
`delete` 运算符：接受一个动态对象的指针，销毁该对象，并释放与之关联的内存

智能指针（定义在 `memory` 头文件中）：

* `shared_ptr` ：允许多个指针指向同一个对象
* `unique_ptr` ：“独占”所指向的对象

智能指针也是模板。

## 12.1.1 shared_ptr 类

shared_ptr 和 unique_ptr 都支持的操作：

* `shared_ptr<T> sp;` / `unique_ptr<T> up;` ：定义一个指向类型为 T 的智能指针，初始化为空指针
* `if (p)` ：将 p 用作一个条件判断，若 p 为空指针，为 false ，若 p 指向一个对象，则为 true
* `*p` ：解引用 p ，获得它指向的对象
* `p->mem` ：等价于 `(*p).mem`
* `p.get()` ：返回 p 中保存的指针。要小心使用，若智能指针释放了其对象，返回的指针所指向的对象也就消失了
* `swap(p, q)` / `p.swap(q)` ：交换 p 和 q 中的指针

shared_ptr 独有的操作：

* `make_shared<T>(args)` ：返回一个 shared_ptr ，指向一个动态分配的类型为 T 的对象，使用 args 初始化该对象
* `shared_ptr<T> p(q);` ：p 是 shared_ptr q 的拷贝；此操作会递增 q 中的计数器，q 中的指针必须能转换为 T*
* `p = q` ：p 和 q 都是 shared_ptr ，所保存的指针必须能相互转换。此操作会递减 p 的引用计数，递增 q 的引用计数；若 p 的引用计数变为 0 ，则将其管理的原内存释放
* `p.unique()` ：若 p.use_count() 为 1 ，返回 true ；否则返回 false
* `p.use_count()` ：返回与 p 共享对象的智能指针数量。可能很慢，主要用于调试

使用 make_shared 函数分配和使用动态内存最安全：

```cpp
auto p = make_shared<T>(args);
// 与 emplace(args) 类似，都是用参数 args 进行初始化
// args 为空，对象就会进行值初始化
```

引用计数递增的情况（只要发生拷贝都会递增）：

1. 用一个 shared_ptr 初始化另一个 shared_ptr
2. 作为参数传递给一个函数（拷贝传递）
3. 作为函数的返回值

引用计数递减的情况：

1. 给一个 shared_ptr 赋予了新值
2. shared_ptr 被销毁（局部 shared_ptr 离开其作用域）

一旦引用计数变为 0 ，shared_ptr 就会自动释放自己管理的对象。使用析构函数完成销毁操作。

shared_ptr 在无用之后仍然保留的情况：

1. 将 shared_ptr 存放在容器中，然后重排该容器。容器尾部的某些 shared_ptr 无用后，并没有调用 erase 删除不再需要的 shared_ptr ，从而导致无用的内存得不到释放。

*注意：容器中不用的元素应该及时调用 erase 删除。*

需要使用动态内存的 3 种情况：

1. 程序不知道自己需要使用多少对象
2. 程序不知道对象的准确类型
3. 程序需要在多个对象之间共享数据

例：定义一个 `StrBlob` 类，是一个容器类。  
与普通的容器类不同：普通的容器类，两个拷贝的对应元素之间相互独立，销毁一个容器，其中的元素也一起销毁。  
`StrBlob` 类，两个拷贝共享相同的元素，销毁一个容器，其中的元素不能销毁，因为另一个容器仍在使用这些元素。

具体实现见[练习 12.2](../src/quiz_12.2.cpp) 。

## 12.1.2 直接管理内存

使用 new/delete 直接管理内存的类不能依赖类对象拷贝、赋值和销毁操作的任何默认定义。

new 动态分配和初始化对象：

```cpp
// 1 默认初始化
int *pi1 = new int;       // *pi1 的值未定义
string *ps1 = new string; // *ps1 为空 string

// 2 直接初始化
int *pi2 = new int(1024);          // *pi2 的值为 1024
string *ps2 = new string(10, '9'); // *ps2 为 "9999999999"
vector<int> *pv = new vector<int>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // *pv 包含 0 到 9

// 3 值初始化（加一对空括号）
int *pi3 = new int();       // *pi3 值初始化为 0
string *ps3 = new string(); // *ps3 值初始化为空 string

// 4 使用初始化器 obj 初始化
auto p1 = new auto(obj);     // p1 的类型是与 obj 对应的指针类型，使用 obj 对 *p1 初始化
auto p2 = new auto{a, b, c}; // 错误：只能出现一个初始化器

// 5 动态分配 const 对象
const int *pci = new const int(1024); // 必须初始化 const 对象
const string *pcs = new const string; // 使用默认构造函数隐式初始化为空的 const string
```

内存耗尽，动态分配对象失败：

```cpp
int *p1 = new int; // 分配失败时 new 会抛出 std::bad_alloc 异常
int *p2 = new(nothrow) int; // 使用定位 new 的方式将 nothrow 传递给 new ，分配失败时 new 返回一个空指针
```

使用 delete 表达式释放动态内存：`delete p;`

delete 执行两个动作：

1. 销毁给定的指针指向的对象
2. 释放对应的内存

delete 表达式对指针的要求：

1. 指针必须指向动态分配的内存（包括 const 动态对象），或者一个空指针
2. 不能释放非 new 分配的内存
3. 不能将相同的指针释放多次

*注意：由内置指针（而不是智能指针）管理的动态内存，在被显式释放之前一直都会存在。*  
*因此应当记得在不需要时使用 delete 释放 new 分配的动态对象。*

*应当坚持使用智能指针，以避免内存泄漏、使用已释放的内存、多次释放同一内存的问题。*

避免使用悬空指针：在 delete 之后将 nullptr 赋予指针变量。

## 12.1.3 shared_ptr 和 new 结合使用

定义和改变 shared_ptr 的其他方法：

* `shared_ptr<T> p(q);` ：q 是指向 new 分配的内存的内置指针，且能够转换为 T* 类型
* `shared_ptr<T> p(u);` ：u 是 unique_ptr ，p 接管了 u 所指对象的所有权，并将 u 置为空
* `shared_ptr<T> p(q, d);` ：p 接管了内置指针 q 所指对象的所有权，p 将使用可调用对象 d 来代替 delete
* `shared_ptr<T> p(p2, d);` ：p 是 shared_ptr p2 的拷贝，p 将使用可调用对象 d 来代替 delete
* `p.reset()` ：若 p 是唯一指向其对象的 shared_ptr ，reset 会释放此对象，并将 p 置为空
* `p.reset(q)` ：q 是内置指针，释放 p 所指对象后，p 会指向 q 的所指对象
* `p.reset(q, d)` ：除上述操作外，还会调用 d 而不是 delete 来释放 q

接受内置指针参数的智能指针构造函数时 explicit 的，不能将一个内置指针隐式转换为一个智能指针。

```cpp
shared_ptr<int> p1(new int(1024));  // 正确：直接初始化
shared_ptr<int> p2 = new int(1024); // 错误：无法进行隐式类型转换
```

*不应该使用内置指针访问 shared_ptr 所指向的内存。*

`get` 函数返回一个内置指针，指向智能指针管理的对象。该函数只适用于“向不支持智能指针的代码传递内置指针”的情况，并且该代码必须保证不能 delete 该指针。

*永远不要用 get 初始化另一个智能指针或者为另一个智能指针赋值。*  
因为另一个智能指针会在其退出作用域时将动态对象的内存释放。

`reset` 与 `unique` 一起使用，在修改底层对象时检查是否有其他代码访问底层动态对象：

```cpp
if (!p.unique()) // 如果引用计数不是 1 ，说明有其他代码正在使用对象
    p.reset(new string(*p)); // 将动态对象 *p 拷贝一份到别的内存区域，然后将指针 p 指向该区域
*p += newVal; // 对拷贝出来的副本进行修改，而不会与其他代码冲突
```

## 12.1.4 智能指针和异常

使用智能指针可以保证：即使程序因为抛出异常而提前结束，动态对象也能够自动销毁。  
而如果在 new 和 delete 之间发生异常，且异常未被捕获，程序提前结束，则动态对象无法被释放。

正确使用智能指针的基本规范：

* 不使用相同的内置指针值初始化或 reset 多个智能指针
* 不 delete get() 返回的指针
* 不使用 get() 初始化或 reset 另一个智能指针
* 如果使用了 get() 返回的指针，记住当最后一个对应的智能指针销毁后，你的指针就变为无效了
* 如果你使用智能指针管理的资源不是 new 分配的内存，记住传递给它一个删除器（见[练习 12.14](../src/quiz_12.14.cpp) 中的 end_connection ）

## 练习

* [练习 12.1](../src/quiz_12.1.md)
* [练习 12.2](../src/quiz_12.2.cpp)
* [练习 12.3](../src/quiz_12.3.md)
* [练习 12.4](../src/quiz_12.4.md)
* [练习 12.5](../src/quiz_12.5.md)
* [练习 12.6](../src/quiz_12.6.cpp)
* [练习 12.7](../src/quiz_12.7.cpp)
* [练习 12.8](../src/quiz_12.8.md)
* [练习 12.9](../src/quiz_12.9.md)
* [练习 12.10](../src/quiz_12.10.md)
* [练习 12.11](../src/quiz_12.11.md)
* [练习 12.12](../src/quiz_12.12.cpp)
* [练习 12.13](../src/quiz_12.13.cpp)
* [练习 12.14](../src/quiz_12.14.cpp)
* [练习 12.15](../src/quiz_12.15.cpp)
