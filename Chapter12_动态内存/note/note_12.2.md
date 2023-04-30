# 12.2 动态数组

*大多数应用都没有直接访问动态数组的需求，而应该使用标准库容器。*

## 12.2.1 new 和数组

### 动态数组的定义

```cpp
int *pia = new int[get_size()]; // 使用 get_size 确定数组的大小

typedef int arrT[42];
int *p = new arrT; // p 指向含有 42 个 int 的数组
```

方括号中的大小必须是整型，但不必是常量。

使用 new 分配动态数组，实际上得到的是指向该数组第一个元素的指针，而非数组类型。  
因此不能调用 begin() 和 end() ，也不能使用范围 for 语句。

### 动态数组的初始化

不能用 auto 分配动态数组，必须显式指定类型。

```cpp
int *pia1 = new int[10];         // 默认初始化
int *pia2 = new int[10]();       // 值初始化为 0
string *psa1 = new string[10];   // 默认初始化为空 string
string *psa2 = new string[10](); // 值初始化为空 string

// 使用初始化器初始化
int *pia3 = new int[10]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
// 前 4 个使用初始化器初始化，后 6 个值初始化
string *psa3 = new string[10]{"a", "an", "the", string(3, 'x')};
```

### 使用 new 分配一个长度为 0 的数组是合法的

```cpp
int arr[0]; // 错误：不能定义长度为 0 的数组
int *p = new int[0]; // 正确：可以分配长度为 0 的动态数组
```

p 此时类似于尾后迭代器，可以加上或减去 0 得到自身；可以减去自身得到 0 ；**不能**对其解引用。

### 动态数组的释放

必须在 delete 和指针中间添加一对空方括号：

```cpp
delete [] p;
```

动态数组中的元素按逆序销毁。

在 delete 动态数组时没加方括号、在 delete 单一对象时添加方括号，编译器可能都不会给出警告，它们的行为是未定义的。

### 可以使用 unique_ptr 管理动态数组

指向动态数组的 unique_ptr 支持的操作：

* `unique_ptr<T[]> u;` ：u 可以指向一个动态分配的数组，数组元素类型为 T
* `unique_ptr<T[]> u(p);` ：u 指向内置指针 p 所指向的动态分配的数组，p 必须能转换为类型 T 的指针
* `u[i]` ：返回 u 指向的动态数组中的第 i 个元素
* 不支持点运算符和箭头运算符

```cpp
// unique_ptr 直接支持动态数组
unique_ptr<int[]> up(new int[10]);
up.release(); // 自动调用 delete [] 销毁动态数组

//shared_ptr 不直接支持动态数组，需要自定义删除器
shared_ptr<int> sp(new int[10], [](int *p) {delete [] p;});
sp.release(); // 调用 lambda 释放动态数组
```

如果没有为 shared_ptr 定义删除器，其行为会与 delete 动态数组时不加方括号相同（行为未定义）。

shared_ptr 与 unique_ptr 不同，其没有下标运算符。

`up[i]` 等价于 `*(sp.get() + i)` 。

## 12.2.2 allocator 类

new 运算符执行时，内存分配和对象构造同时进行。  
使用 allocator 类，可以将内存分配和对象构造分开：先申请一块内存，之后按照需求构造对象。

allocator 支持的操作：

* `allocator<T> a;` ：定义一个名为 a 的 allocator 对象，它可以为类型 T 的对象分配内存
* `a.allocate(n)` ：分配一段原始的、未构造的内存，能够保存 n 个类型为 T 的对象
* `a.deallocate(p, n)` ：释放从指针 p 所指对象开始的 n 个对象所占用的内存；p 必须是先前由 allocate 返回的指针；n 必须是创建 p 时指定的大小；这 n 个对象必须都要事先调用 destroy
* `a.construct(p, args)` ：p 是一个类型为 T* 的指针，指向一块原始的、未构造的内存，使用 args 参数调用构造函数，在 p 所指内存中构造一个对象
* `a.destroy(p)` ：对 p 所指对象执行析构函数

示例：

```cpp
allocator<string> alloc;
auto const p = alloc.allocate(n); // p 所指内存块可以容纳 n 个 string 对象

auto q = p; // q 指向已构造元素的尾后位置
alloc.construct(q++);          // 构造第一个 string 为空字符串
alloc.construct(q++, 10, 'c'); // 构造第二个 string 为 cccccccccc
alloc.construct(q++, "hi");    // 构造第三个 string 为 hi

cout << *p << endl; // 输出第一个 string 对象
cout << *q << endl; // 错误：不能解引用未构造的内存，其行为是未定义的

// 析构刚才构造的 3 个 string 对象
while (q != p)
    alloc.destroy(--q);

// 释放全部内存
alloc.deallocate(p, n);
```

与 allocator 搭配使用的算法（算法返回最后一个构造的元素之后的位置）：

* `uninitialized_copy(b, e, p)` ：从迭代器范围 b 到 e 中拷贝元素到指针 p 指向的未构造的原始内存中，p 指向的原始内存必须足够大
* `uninitialized_copy_n(b, n, p)` ：从迭代器 b 指向的元素开始，拷贝 n 个元素到指针 p 指向的未构造的原始内存中，p 指向的原始内存必须足够大
* `uninitialized_fill(p, q, t)` ：在指针 p 到 q 的原始内存范围中创建对象，对象的值均为 t 的拷贝
* `uninitialized_fill_n(p, n, t)` ：从指针 p 指向的原始内存地址开始，创建 n 个对象，对象的值均为 t 的拷贝

示例：

```cpp
vector<int> vi = {0, 1, 2, 3, 4, 5};
allocator<int> alloc;
auto const p = alloc.allocate(vi.size() * 2); // 分配两倍于 vi 长度的内存

auto q = uninitialized_copy(vi.begin(), vi.end()， p); // 使用 vi 的元素构造前一半内存的元素
uninitialized_fill_n(q, vi.size(), 42); // 使用 42 构造后一半内存的元素
```

## 练习

* [练习 12.23](../src/quiz_12.23.cpp)
* [练习 12.24](../src/quiz_12.24.cpp)
* [练习 12.25](../src/quiz_12.25.md)
* [练习 12.26](../src/quiz_12.26.cpp)
