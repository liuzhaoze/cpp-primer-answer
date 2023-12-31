# 7.4 类的作用域

> 本章术语：
>  
> * 名字查找（name lookup）：寻找与所用名字最匹配的声明的过程

## 7.4.1 名字查找与类的作用域

名字查找过程：

1. 首先，在名字所在的块中寻找其声明语句，只考虑在名字的使用之前出现的声明
2. 如果没找到，继续查找外层作用域
3. 如果最终没有找到匹配的声明，则程序报错

类的定义分两步处理：

1. 首先，编译成员的声明
2. 直到类全部可见后才编译函数体

*编译器处理完类中的全部声明后才会处理成员函数的定义。*  
因此，成员函数可以使用类中定义的任何名字。

一般来说，内层作用域可以重新定义外层作用域中的名字，即使该名字已经在内层作用于中使用过。  
但是在类的定义中，如果成员使用了外层作用域中的名字，而该名字代表一种类型，则在类中不能再重新定义该名字。

```c
typedef double Money;
class Account
{
public:
    Money balance(void) { return bal; } // 使用了外层作用域中的 Money

private:
    typedef double Money; // 错误：不能再重新定义 Money
    Money bal;
}
```

*类型名的定义通常出现在类的开始处，这样就能确保所有使用该类型的成员都出现在类名的定义之后。*

在成员函数中使用的名字按照如下方式解析：

1. 首先，在成员函数内查找该名字的声明。只有在函数使用之前出现的声明才被考虑。
2. 如果在成员函数内没有找到，则在类内继续查找，这时类的所有成员都可以被考虑。
3. 如果类内也没找到该名字的声明，在成员函数定义之前的作用域内继续查找。

*不建议使用其他成员的名字作为某个成员函数的形式参数。*  
*不要把成员名字作为形参或其他局部变量使用。*  
*不要隐藏外层（全局）作用域中可能被用到的名字。*

当成员函数定义在类的外部时，名字查找的第三步不仅要考虑类定义之前的全局作用域中的声明，还要考虑在成员函数定义之前的全局作用域中的声明。

## 练习

* [练习 7.33](../src/quiz_7.33.hpp)
* [练习 7.34](../src/quiz_7.34.md)
* [练习 7.35](../src/quiz_7.35.cpp)
