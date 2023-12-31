# 3.5 数组

## 3.5.1 定义和初始化内置数组

数组维度必须是一个常量表达式。

不存在引用的数组。

可以对数组的元素进行列表初始化。

不允许数组的拷贝和赋值。

要想理解数组声明的含义，最好的办法是从数组的名字开始按照由内向外的顺序阅读。

## 3.5.2 访问数组元素

数组的元素也能使用范围 for 语句或下标运算符来访问。

在使用数组下标的时候，通常将其定义为 `size_t` 类型。  
在 `cstddef` 头文件中定义了 `size_t` 类型。

## 3.5.3 指针和数组

在很多用到数组名字的地方，编译器都会自动地将其替换为一个指向数组首元素的指针。

当使用数组作为一个 auto 变量的初始值时，推断得到的类型是指针而非数组。

当使用 decltype 关键字时，其返回的类型是数组，而不是指针。

`begin` 函数返回指向数组首元素的指针， `end` 函数返回指向数组尾元素下一位置的指针。
这两个函数定义在 iterator 头文件中，且不是成员函数。

尾后指针不能执行解引用和递增操作。

两个指针相减的结果的类型是一种名为 `ptrdiff_t` 的带符号标准库类型。其定义在 `cstddef` 头文件中。

*如果表达式含有解引用运算符和点运算符，最好在必要的地方加上圆括号。*

标准库类型限定使用的下标必须是无符号类型，而内置的下标运算无此要求。

## 3.5.4 C 风格字符串

C 风格字符串的函数（定义在 `cstring` 头文件中）。

```c
strlen(p)
strcmp(p1, p2)
strcat(p1, p2)
strcpy(p1, p2)
```

**传入以上函数的指针必须指向以空字符作为结束的数组。**

## 3.5.5 与旧代码的接口

任何出现字符串字面值的地方都可以用以空字符结束的字符数组来替代。

string 提供了一个名为 c_str 的成员函数，其返回一个 C 风格的字符串，返回值类型是 `const char *` 。

```c
const char *str = s.c_str();
```

使用数组初始化 vector 对象：指明要拷贝区域的首元素地址和尾后地址。

```c
int ia[] = {0, 1, 2, 3, 4, 5};
vector<int> ivec(begin(ia), end(ia));
vector<int> ivec(ia + 1, ia + 4);  // 使用数组的一部分初始化 vector
```

*建议尽量使用标准库类型而非数组。*

## 练习

* [练习 3.27](../src/quiz_3.27.cpp)
* [练习 3.28](../src/quiz_3.28.cpp)
* [练习 3.29](../src/quiz_3.29.md)
* [练习 3.30](../src/quiz_3.30.cpp)
* [练习 3.31](../src/quiz_3.31.cpp)
* [练习 3.32](../src/quiz_3.32.cpp)
* [练习 3.33](../src/quiz_3.33.md)
* [练习 3.34](../src/quiz_3.34.md)
* [练习 3.35](../src/quiz_3.35.cpp)
* [练习 3.36](../src/quiz_3.36.cpp)
* [练习 3.37](../src/quiz_3.37.cpp)
* [练习 3.38](../src/quiz_3.38.md)
* [练习 3.39](../src/quiz_3.39.cpp)
* [练习 3.40](../src/quiz_3.40.cpp)
* [练习 3.41](../src/quiz_3.41.cpp)
* [练习 3.42](../src/quiz_3.42.cpp)
