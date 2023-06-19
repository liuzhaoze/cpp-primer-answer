# 19.1 控制内存分配

> 本章术语：
>
> * 定位 new （placement new）：用于初始化 operator new 函数分配的内存

为了实现使用关键字 new 将对象放置在特定的内存空间中，需要重载 new 运算符和 delete 运算符。

## 19.1.1 重载 new 和 delete

new 表达式的执行包含 3 步操作：

1. new 表达式调用 `operator new` 或 `operator new[]` 标准库函数，分配一块足够大的、原始的、未命名的内存空间，以便储存特定类型的对象或对象的数组
2. 编译器运行相应的构造函数以构造这些对象，并为其传入初始值
3. 对象被分配了空间并构造完成，返回一个指向该对象的指针

delete 表达式的执行包含 2 步操作：

1. 对指针所指的对象或数组中的元素执行对应的析构函数
2. 调用 `operator delete` 或 `operator delete[]` 标准库函数释放内存空间

如果我们希望自己控制内存分配的过程，则需要定义自己的 `operator new` 函数和 `operator delete` 函数。

`operator new` 函数和 `operator delete` 函数既可以在全局作用域中定义，也可以在类中定义为成员函数。  
如果被分配/释放的对象是类类型，则编译器首先在类及其基类的作用域中查找 `operator new` / `operator delete` 成员。如果编译器没有找到成员函数，则会在全局作用域中查找匹配的函数。如果找到了用户自定义的版本，则使用该版本，否则使用标准库定义的版本。  
`::new` 和 `::delete` 直接调用全局作用域中的版本。

标准库允许重载的 new 运算符：

```cpp
// 可能抛出 bad_alloc 异常的版本
void *operator new(size_t);
void *operator new[](size_t);
// 不会抛出异常的版本
void *operator new(size_t, nothrow_t &) noexcept;
void *operator new[](size_t, nothrow_t &) noexcept;

// size_t 为要存储的对象的字节总数
```

可以为 new 运算符提供额外的形参，但不能重载 `void *operator new(size_t, void *);` ，这是标准库独占版本。

标准库允许重载的 delete 运算符：

```cpp
// 可能抛出 bad_alloc 异常的版本
void operator delete(void *) noexcept;
void operator delete[](void *) noexcept;
// 不会抛出异常的版本
void operator delete(void *, nothrow_t &) noexcept;
void operator delete[](void *, nothrow_t &) noexcept;

// void * 为待释放内存的指针
```

nothrow_t 是 `<new>` 头文件中的 struct 类型。

用户可以通过 `<new>` 头文件中的 nothrow 对象请求不抛出异常的 new 版本。

应该使用 `<cstdlib>` 头文件中的 `malloc` 和 `free` 函数实现 new 和 delete 运算符：

```cpp
void *operator new(size_t size)
{
    if (void *mem = malloc(size)) // 申请 size 字节大小的内存，并测试是否申请成功
    {
        return mem;
    }
    else
    {
        throw bad_alloc();
    }
}

void operator delete(void *mem) noexcept
{
    free(mem);
}
```

## 19.1.2 定位 new 表达式

对于 `operator new` 函数分配的内存空间，应该使用**定位 new 表达式**构造对象：

```cpp
new (place_address) type
new (place_address) type (initializers)
new (place_address) type [size]
new (place_address) type [size] { braced initializer list }
```

在 `place_address` 所指内存处构造 `type` 类型的对象或 `size` 大小的数组。

直接调用析构函数会销毁对象，但不会释放原对象所占的内存：

```cpp
string *ps = new string("a value"); // 分配内存并在内存中构造一个 string 对象
ps->~string(); // 只销毁了 string 对象，并没有释放已分配的内存
```

## 练习

* [练习 19.1](../src/quiz_19.1.cpp)
* [练习 19.2](../src/quiz_19.2.cpp)
