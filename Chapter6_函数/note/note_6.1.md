# 6.1 函数基础

> 本章术语：
>  
> * 返回类型（return type）
> * 形参（parameter）
> * 实参（argument）
> * 函数体（function body）
> * 调用运算符（call operator）：调用运算符的形式是一对圆括号，作用于一个表达式，该表达式是函数或指向函数的指针。括号内是用逗号隔开的实参列表。
> * 主调函数（calling function）
> * 被调函数（called function）
> * 生命周期（lifetime）：一个对象在程序执行过程中存在的一段时间。
> * 局部变量（local variable）：形参和函数体内部定义的变量。
> * 自动对象（automatic object）：只存在于块执行期间的对象。
> * 局部静态对象（local static object）：第一次初始化后，直到程序终止才被销毁，即使对象所在的函数结束执行也不会对其造成影响。
> * 函数原型（function prototype）：函数声明。

## 6.1.1 局部对象

形参是一种自动对象。

局部变量对应的自动对象，如果变量定义本身含有初始值，则用初始值进行初始化；否则执行默认初始化。（内置类型的未初始化局部变量将产生未定义的值）

如果局部静态变量没有显式的初始值，则执行值初始化。（内置类型的局部静态变量初始化为 0 。

## 6.1.2 函数声明

含有函数声明的头文件应该被包含到定义函数的源文件中。

## 6.1.3 分离式编译

## 练习

* [练习 6.1](../src/quiz_6.1.md)
* [练习 6.2](../src/quiz_6.2.md)
* [练习 6.3](../src/quiz_6.3.cpp)
* [练习 6.4](../src/quiz_6.4.cpp)
* [练习 6.5](../src/quiz_6.5.cpp)
* [练习 6.6](../src/quiz_6.6.md)
* [练习 6.7](../src/quiz_6.7.cpp)
* [练习 6.8](../src/quiz_6.8.h)
* [练习 6.9](../src/quiz_6.9_main.cpp)
