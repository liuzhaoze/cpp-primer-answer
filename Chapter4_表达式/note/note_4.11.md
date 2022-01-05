# 4.11 类型转换

> 本章术语：
>  
> * 隐式转换（implicit conversion）
> * 算术转换（arithmetic conversion）
> * 整型提升（integral promotion）
> * 强制类型转换（cast）

发生隐式转换的情况：

* 在大多数表达式中，比 int 类型小的整型值首先提升为较大的整数类型。
* 在条件中，非布尔值转换成布尔类型。
* 在初始化过程中，初始值转换成变量的类型；在赋值语句中，右侧运算对象转换成左侧运算对象的类型。
* 如果算术运算或关系运算的运算对象有多种类型，则需要转换成同一种类型。
* 函数调用时也会发生类型转换。

## 4.11.1 算术转换

## 4.11.2 其他隐式类型转换

* 数组转换成指针：  
  而当数组被用作 decltype 关键字的参数，或者作为取地址符（ `&` ）、 `sizeof` 、 `typeid` 等运算符的运算对象时，则不会转换
* 指针的转换：  
  指向任意非常量的指针都能转换成 `void *` ；  
  指向任意对象的指针都能转换成 `const void *` 。
* 转换成布尔类型
* 转换成常量
* 类类型定义的转换

## 4.11.3 显式转换

命名的强制类型转换：

```c
cast-name<type>(expression);
```

type 是转换的目标类型； expression 是要转换的值。  
如果 type 是引用类型，则结果是左值。  
cast-name 是 `static_cast` 、 `dynamic_cast` 、 `const_cast` 、 `reinterpret_cast` 中的一种。

* static_cast  
  任何具有明确定义的类型转换，只要不包含底层 const ，都可以使用 static_cast 。
* const_cast  
  只能改变运算对象的底层 const 。
* reinterpret_cast
* dynamic_cast

*建议避免强制类型转换。*

## 练习

* [练习 4.34](../src/quiz_4.34.md)
* [练习 4.35](../src/quiz_4.35.md)
* [练习 4.36](../src/quiz_4.36.cpp)
* [练习 4.37](../src/quiz_4.37.cpp)
* [练习 4.38](../src/quiz_4.38.md)
