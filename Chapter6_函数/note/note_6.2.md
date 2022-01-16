# 6.2 参数传递

> 本章术语：
>  
> * 引用传递（passed by reference）：形参是引用类型，实参被引用传递。
> * 传引用调用（called by reference）：形参是引用类型，函数被传引用调用。
> * 值传递（passed by value）：实参的值拷贝给形参，实参被值传递。
> * 传值调用（called by value）：实参的值拷贝给形参，函数被传值调用。

## 6.2.1 传值参数

实参的值拷贝给形参，对形参的改变不会影响实参。

*在 C 语言中，常常使用指针类型的形参访问函数外部的对象；*  
*在 C++ 中，建议使用引用类型的形参代替指针。*

## 6.2.2 传引用参数

如果函数无需改变引用形参的值，最好将其声明为常量引用。

## 6.2.3 const 形参和实参

当用实参初始化形参时会忽略掉顶层 const 。当形参有顶层 const 时，传给他常量对象或者非常量对象都是可以的。

C++ 允许定义若干具有相同名字的函数，前提是不同函数的形参列表应该有明显的区别。

*尽量使用常量引用形参*  
使用普通的引用形参会带给函数调用者一种误导：函数可以修改他的实参的值。  
const 对象、字面值或者需要类型转换的对象**不能**传递给普通的引用形参。

## 6.2.4 数组形参

管理指针形参的三种常用技术：

* 使用标记指定数组长度： C 风格字符串。
* 使用标准库规范：传递指向数组首元素和尾后元素的指针。
* 显式传递一个表示数组大小的形参。

```c
// 数组指针形参（三者等价）
void print(const int *);
void print(const int[]);
void print(const int[10]);

// 数组引用形参（传入的数组大小必须是10）
void print(int (&arr)[10]);
```

多维数组：

```c
void print(int (*matrix)[10], int rowSize);
void print(int matrix[][10], int rowSize);
```

## 6.2.5 main：处理命令行选项

`int main(int argc, char *argv[]) { ... }`

argv 的第一个元素指向程序的名字或者一个空字符串，接下来的元素依次指向命令行提供的实参。最后一个指针之后的元素保证为 0 。

## 6.2.6 含有可变性参的函数

1. 如果所有的实参类型相同，可以传递一个名为 initializer_list 的标准库类型
2. 如果实参的类型不同，可以使用可变参数模板
3. 使用省略符形参类型（一般只用于与 C 函数交互的接口程序）

`<initializer_list>` 提供的操作

```c
initializer_list<T> lst;
initializer_list<T> lst{a, b, c, ...};
lst2(lst)  // 不会拷贝列表中的元素，两者共享元素
lst2 = lst // 不会拷贝列表中的元素，两者共享元素
lst.size()
lst.begin()
lst.end()
```

initializer_list 对象中的元素永远是常量值，无法改变 initializer_list 对象中元素的值。

如果想向 initializer_list 形参中传递一个值的序列，必须把序列放在一对花括号内。

```c
void error_msg(initializer_list<string> lst);
error_msg({"AAA", "BBB", string});
```

可以使用范围 for 循环处理 initializer_list 中的元素。

*省略符形参应该仅仅用于 C 和 C++ 通用的类型。大多数 类 类型的对象在传递给省略符形参时都无法正确拷贝。*

```c
void function(parm_list, ...);
void function(...);
```

## 练习

* [练习 6.10](../src/quiz_6.10.cpp)
* [练习 6.11](../src/quiz_6.11.cpp)
* [练习 6.12](../src/quiz_6.12.cpp)
* [练习 6.13](../src/quiz_6.13.md)
* [练习 6.14](../src/quiz_6.14.md)
* [练习 6.15](../src/quiz_6.15.md)
* [练习 6.16](../src/quiz_6.16.md)
* [练习 6.17](../src/quiz_6.17.cpp)
* [练习 6.18](../src/quiz_6.18.md)
* [练习 6.19](../src/quiz_6.19.md)
* [练习 6.20](../src/quiz_6.20.md)
* [练习 6.21](../src/quiz_6.21.cpp)
* [练习 6.22](../src/quiz_6.22.cpp)
* [练习 6.23](../src/quiz_6.23.cpp)
* [练习 6.24](../src/quiz_6.24.md)
* [练习 6.25](../src/quiz_6.25.cpp)
* [练习 6.26](../src/quiz_6.26.cpp)
* [练习 6.27](../src/quiz_6.27.cpp)
* [练习 6.28](../src/quiz_6.28.cpp)
* [练习 6.29](../src/quiz_6.29.md)
