# 6.3 返回类型和 return 语句

> 本章术语：
>  
> * 尾置返回类型（trailing return type）

## 6.3.1 无返回值的函数

没有返回值的 return 语句只能用在返回类型是 void 的函数中。  
返回 void 的函数不要求一定要有 return 语句。这类函数的最后一句后面会隐式地执行 return 。

一个返回类型是 void 的函数也能使用 return *expression* 形式。不过此时 return 语句的 *expression* 必须是另一个返回 void 的函数。

## 6.3.2 有返回值的函数

只要函数的返回类型不是 void ，则该函数内的每条 return 语句必须返回一个值。  
return 语句返回值的类型必须与函数的返回类型相同，或者能隐式地转换成函数的返回类型。

*不要返回局部对象的引用或指针。* 因为函数完成后，局部对象占用的存储空间会被释放，引用或指针将指向不再有效的内存区域。

返回**引用类型**的函数得到左值，其他返回类型得到右值。

`cstdlib` 头文件定义了两个预处理变量 `EXIT_SUCCESS` 和 `EXIT_FAILURE` 用于 main 函数的返回值。

在递归函数中，一定有某条路径是不包含递归调用的。否则函数将一直递归下去。

## 6.3.3 返回数组指针

使用类型别名： `using arrT = int[10]; arrT* func(int i);`

返回数组指针的函数形式： `Type (*function(parameter_list))[dimension]`

尾置返回类型： `auto func(int i) -> int (*)[10];`

使用 decltype ： `int arr[10]; decltype(arr) *func(int i);`

## 练习

* [练习 6.30](../src/quiz_6.30.cpp)
* [练习 6.31](../src/quiz_6.31.md)
* [练习 6.32](../src/quiz_6.32.cpp)
* [练习 6.33](../src/quiz_6.33.cpp)
* [练习 6.34](../src/quiz_6.34.md)
* [练习 6.35](../src/quiz_6.35.md)
* [练习 6.36](../src/quiz_6.36.cpp)
* [练习 6.37](../src/quiz_6.37.cpp)
* [练习 6.38](../src/quiz_6.38.cpp)
