# 19.8 固有的不可移植的特性

> 本章术语：
>
> * 不可移植（nonportable）：因机器而异的特性，在不同的物理机中需要根据实际情况修改的代码
> * 位域（bit-field）：类可以将非静态数据成员定义成位域，用于向其他程序或硬件设备传递二进制数据
> * 链接指示（linkage directive）：指出任意非 C++ 函数所用的语言

## 19.8.1 位域

通常情况下使用无符号类型保存一个位域：

```cpp
using Bit = unsigned int;

class File {
private:
    Bit mode       : 2; // mode 占 2 位
    Bit modified   : 1; // modified 占 1 位
    Bit prot_owner : 3; // prot_owner 占 3 位
    Bit prot_group : 3; // prot_group 占 3 位
    Bit prot_world : 3; // prot_world 占 3 位

public:
    enum modes { READ = 01, WRITE = 02, EXECUTE = 03 };
    File &open(modes);
    void close();
    void write();
    bool isRead() const;
    void setWrite();
};
```

在类的内部连续定义的位域压缩在同一整数的相邻位。

位域的使用方法：

```cpp
void File::write()
{
    modified = 1; // 置位
}

void File::close()
{
    if (modified) // 作为条件
        // 保存内容
}

File &File::open(File::modes m)
{
    mode |= READ; // 设置 READ

    if (m & WRITE) // 测试 WRITE
        // ...

    return *this;
}
```

如果一个类定义了位域成员，则它通常也会定义一组内联的成员函数以检验或设置位域的值：

```cpp
// 检验
inline bool File::isRead() const { return mode & READ; }

// 设置
inline void File::setWrite() { mode |= WRITE; }
```

## 19.8.2 volatile 限定符

当对象的值可能被硬件改变时（例如使用时钟更新的定时器），应该将该对象声明为 `volatile` 的，编译器不会对这样的对象进行优化。

```cpp
volatile int v; // v 是 volatile int
int *volatile vip; // vip 是一个 volatile 指针，指向 int
volatile int *ivp; // ivp 是一个指针，指向 volatile int
volatile int *volatile vivp; // vivp 是一个 volatile 指针，指向 volatile int
```

不能使用合成的拷贝/移动构造函数及合成的拷贝/移动赋值运算符初始化 volatile 对象或从 volatile 对象赋值。

## 19.8.3 链接指示：extern "C"

链接指示不能出现在类定义或函数定义的内部。

```cpp
// 单语句链接指示
extern "C" size_t strlen(const char *);

// 复合语句链接指示
extern "C" {
    #include <string.h> // 包含头文件中的所有函数
    int strcmp(const char *, const char *);
    char *strcat(char *, const char *);
}
```

链接指示是函数类型的一部分：

```cpp
extern "C" void (*pf1)(int); // pf1 指向 C 语言实现的函数
void (*pf2)(int);            // pf2 指向 C++ 实现的函数
pf1 = pf2;                   // 错误：两者类型不同
```

链接指示对整个声明都有效：

```cpp
extern "C" void f(void (*pf)(int));
// 不仅函数 f 是用 C 语言实现的函数，而且 pf 也是指向用 C 语言实现的函数的指针
```

使源文件同时兼容 C 语言编译器和 C++ 编译器：

```cpp
#ifdef __cplusplus
extern "C"
#endif
int strcmp(const char *, const char *);
```

只有目标语言支持重载函数，链接指示中才能声明重载函数。

## 练习

* [练习 19.26](../src/quiz_19.26.md)
