# C++ Primer 中文版：第 5 版 读书笔记/课后练习

> 注意：
>
> * 每节练习位于笔记末尾。
> * 编译时注意依赖。如果出现了链接错误，绝大多数情况是因为没有将自己编写的头文件对应的 `.cpp` 文件添加到编译命令中。参考[练习 13.42](./Chapter13_%E6%8B%B7%E8%B4%9D%E6%8E%A7%E5%88%B6/src/quiz_13.42_main.cpp) 。
> * [lib](./lib/) 中的类模板代码是在非模板代码基础上修改而来的，未经测试，且定义应该在头文件而非源文件中。

测试用例来自[该网站](https://www.informit.com/store/c-plus-plus-primer-9780321714114)。

部分答案参考 [Mooophy/Cpp-Primer](https://github.com/Mooophy/Cpp-Primer) 。

## 第 1 章 开始

### 1.1 [编写一个简单的 C++ 程序](./Chapter1_%E5%BC%80%E5%A7%8B/note/note_1.1.md)

#### 1.1.1 编译、运行程序

### 1.2 [初识输入输出](./Chapter1_%E5%BC%80%E5%A7%8B/note/note_1.2.md)

### 1.3 [注释简介](./Chapter1_%E5%BC%80%E5%A7%8B/note/note_1.3.md)

### 1.4 [控制流](./Chapter1_%E5%BC%80%E5%A7%8B/note/note_1.4.md)

#### 1.4.1 while 语句

#### 1.4.2 for 语句

#### 1.4.3 读取数量不定的输入数据

#### 1.4.4 if 语句

### 1.5 [类简介](./Chapter1_%E5%BC%80%E5%A7%8B/note/note_1.5.md)

#### 1.5.1 Sales_item 类

#### 1.5.2 初识成员函数

### 1.6 [书店程序](./Chapter1_%E5%BC%80%E5%A7%8B/note/note_1.6.md)

## 第 2 章 变量和基本类型

### 2.1 [基本内置类型](./Chapter2_%E5%8F%98%E9%87%8F%E5%92%8C%E5%9F%BA%E6%9C%AC%E7%B1%BB%E5%9E%8B/note/note_2.1.md)

#### 2.1.1 算术类型

#### 2.1.2 类型转换

#### 2.1.3 字面值常量

### 2.2 [变量](./Chapter2_%E5%8F%98%E9%87%8F%E5%92%8C%E5%9F%BA%E6%9C%AC%E7%B1%BB%E5%9E%8B/note/note_2.2.md)

#### 2.2.1 变量定义

#### 2.2.2 变量声明与定义的关系

#### 2.2.3 标识符

#### 2.2.4 名字的作用域

### 2.3 [复合类型](./Chapter2_%E5%8F%98%E9%87%8F%E5%92%8C%E5%9F%BA%E6%9C%AC%E7%B1%BB%E5%9E%8B/note/note_2.3.md)

#### 2.3.1 引用

#### 2.3.2 指针

#### 2.3.3 理解复合类型的声明

### 2.4 [const 限定符](./Chapter2_%E5%8F%98%E9%87%8F%E5%92%8C%E5%9F%BA%E6%9C%AC%E7%B1%BB%E5%9E%8B/note/note_2.4.md)

#### 2.4.1 const 的引用

#### 2.4.2 指针和 const

#### 2.4.3 顶层 const

#### 2.4.4 constexpr 和常量表达式

### 2.5 [处理类型](./Chapter2_%E5%8F%98%E9%87%8F%E5%92%8C%E5%9F%BA%E6%9C%AC%E7%B1%BB%E5%9E%8B/note/note_2.5.md)

#### 2.5.1 类型别名

#### 2.5.2 auto 类型说明符

#### 2.5.3 decltype 类型指示符

### 2.6 [自定义数据结构](./Chapter2_%E5%8F%98%E9%87%8F%E5%92%8C%E5%9F%BA%E6%9C%AC%E7%B1%BB%E5%9E%8B/note/note_2.6.md)

#### 2.6.1 定义 Sales_data 类型

#### 2.6.2 使用 Sales_data 类

#### 2.6.3 编写自己的头文件

## 第 3 章 字符串、向量和数组

### 3.1 [命名空间的 using 声明](./Chapter3_%E5%AD%97%E7%AC%A6%E4%B8%B2%E3%80%81%E5%90%91%E9%87%8F%E5%92%8C%E6%95%B0%E7%BB%84/note/note_3.1.md)

### 3.2 [标准库类型 string](./Chapter3_%E5%AD%97%E7%AC%A6%E4%B8%B2%E3%80%81%E5%90%91%E9%87%8F%E5%92%8C%E6%95%B0%E7%BB%84/note/note_3.2.md)

#### 3.2.1 定义和初始化 string 对象

#### 3.2.2 string 对象上的操作

#### 3.2.3 处理 string 对象中的字符

### 3.3 [标准库类型 vector](./Chapter3_%E5%AD%97%E7%AC%A6%E4%B8%B2%E3%80%81%E5%90%91%E9%87%8F%E5%92%8C%E6%95%B0%E7%BB%84/note/note_3.3.md)

#### 3.3.1 定义和初始化 vector 对象

#### 3.3.2 向 vector 对象中添加元素

#### 3.3.3 其他 vector 操作

### 3.4 [迭代器介绍](./Chapter3_%E5%AD%97%E7%AC%A6%E4%B8%B2%E3%80%81%E5%90%91%E9%87%8F%E5%92%8C%E6%95%B0%E7%BB%84/note/note_3.4.md)

#### 3.4.1 使用迭代器

#### 3.4.2 迭代器运算

### 3.5 [数组](./Chapter3_%E5%AD%97%E7%AC%A6%E4%B8%B2%E3%80%81%E5%90%91%E9%87%8F%E5%92%8C%E6%95%B0%E7%BB%84/note/note_3.5.md)

#### 3.5.1 定义和初始化内置数组

#### 3.5.2 访问数组元素

#### 3.5.3 指针和数组

#### 3.5.4 C 风格字符串

#### 3.5.5 与旧代码的接口

### 3.6 [多维数组](./Chapter3_%E5%AD%97%E7%AC%A6%E4%B8%B2%E3%80%81%E5%90%91%E9%87%8F%E5%92%8C%E6%95%B0%E7%BB%84/note/note_3.6.md)

## 第 4 章 表达式

### 4.1 [基础](./Chapter4_%E8%A1%A8%E8%BE%BE%E5%BC%8F/note/note_4.1.md)

#### 4.1.1 基础概念

#### 4.1.2 优先级与结合律

#### 4.1.3 求值顺序

### 4.2 [算数运算符](./Chapter4_%E8%A1%A8%E8%BE%BE%E5%BC%8F/note/note_4.2.md)

### 4.3 [逻辑和关系运算符](./Chapter4_%E8%A1%A8%E8%BE%BE%E5%BC%8F/note/note_4.3.md)

### 4.4 [赋值运算符](./Chapter4_%E8%A1%A8%E8%BE%BE%E5%BC%8F/note/note_4.4.md)

### 4.5 [递增和递减运算符](./Chapter4_%E8%A1%A8%E8%BE%BE%E5%BC%8F/note/note_4.5.md)

### 4.6 [成员访问运算符](./Chapter4_%E8%A1%A8%E8%BE%BE%E5%BC%8F/note/note_4.6.md)

### 4.7 [条件运算符](./Chapter4_%E8%A1%A8%E8%BE%BE%E5%BC%8F/note/note_4.7.md)

### 4.8 [位运算符](./Chapter4_%E8%A1%A8%E8%BE%BE%E5%BC%8F/note/note_4.8.md)

### 4.9 [sizeof 运算符](./Chapter4_%E8%A1%A8%E8%BE%BE%E5%BC%8F/note/note_4.9.md)

### 4.10 [逗号运算符](./Chapter4_%E8%A1%A8%E8%BE%BE%E5%BC%8F/note/note_4.10.md)

### 4.11 [类型转换](./Chapter4_%E8%A1%A8%E8%BE%BE%E5%BC%8F/note/note_4.11.md)

#### 4.11.1 算术转换

#### 4.11.2 其他隐式类型转换

#### 4.11.3 显式转换

### 4.12 [运算符优先级表](./Chapter4_%E8%A1%A8%E8%BE%BE%E5%BC%8F/note/note_4.12.md)

## 第 5 章 语句

### 5.1 [简单语句](./Chapter5_%E8%AF%AD%E5%8F%A5/note/note_5.1.md)

### 5.2 [语句作用域](./Chapter5_%E8%AF%AD%E5%8F%A5/note/note_5.2.md)

### 5.3 [条件语句](./Chapter5_%E8%AF%AD%E5%8F%A5/note/note_5.3.md)

#### 5.3.1 if 语句

#### 5.3.2 switch 语句

### 5.4 [迭代语句](./Chapter5_%E8%AF%AD%E5%8F%A5/note/note_5.4.md)

#### 5.4.1 while 语句

#### 5.4.2 传统的 for 语句

#### 5.4.3 范围 for 语句

#### 5.4.4 do while 语句

### 5.5 [跳转语句](./Chapter5_%E8%AF%AD%E5%8F%A5/note/note_5.5.md)

#### 5.5.1 break 语句

#### 5.5.2 continue 语句

#### 5.5.3 goto 语句

### 5.6 [try 语句块和异常处理](./Chapter5_%E8%AF%AD%E5%8F%A5/note/note_5.6.md)

#### 5.6.1 throw 表达式

#### 5.6.2 try 语句块

#### 5.6.3 标准异常

## 第 6 章 函数

### 6.1 [函数基础](./Chapter6_%E5%87%BD%E6%95%B0/note/note_6.1.md)

#### 6.1.1 局部对象

#### 6.1.2 函数声明

#### 6.1.3 分离式编译

### 6.2 [参数传递](./Chapter6_%E5%87%BD%E6%95%B0/note/note_6.2.md)

#### 6.2.1 传值参数

#### 6.2.2 传引用参数

#### 6.2.3 const 形参和实参

#### 6.2.4 数组形参

#### 6.2.5 main：处理命令行选项

#### 6.2.6 含有可变形参的函数

### 6.3 [返回类型和 return 语句](./Chapter6_%E5%87%BD%E6%95%B0/note/note_6.3.md)

#### 6.3.1 无返回值函数

#### 6.3.2 有返回值函数

#### 6.3.3 返回数组指针

### 6.4 [函数重载](./Chapter6_%E5%87%BD%E6%95%B0/note/note_6.4.md)

#### 6.4.1 重载与作用域

### 6.5 [特殊用途语言特性](./Chapter6_%E5%87%BD%E6%95%B0/note/note_6.5.md)

#### 6.5.1 默认实参

#### 6.5.2 内联函数和 constexpr 函数

#### 6.5.3 调试帮助

### 6.6 [函数匹配](./Chapter6_%E5%87%BD%E6%95%B0/note/note_6.6.md)

#### 6.6.1 实参类型转换

### 6.7 [函数指针](./Chapter6_%E5%87%BD%E6%95%B0/note/note_6.7.md)

## 第 7 章 类

### 7.1 [定义抽象数据类型](./Chapter7_%E7%B1%BB/note/note_7.1.md)

#### 7.1.1 设计 Sales_data 类

#### 7.1.2 定义改进的 Sales_data 类

#### 7.1.3 定义类相关的非成员函数

#### 7.1.4 构造函数

#### 7.1.5 拷贝、赋值和析构

### 7.2 [访问控制与封装](./Chapter7_%E7%B1%BB/note/note_7.2.md)

#### 7.2.1 友元

### 7.3 [类的其他特性](./Chapter7_%E7%B1%BB/note/note_7.3.md)

#### 7.3.1 类成员再探

#### 7.3.2 返回 *this 的成员函数

#### 7.3.3 类类型

#### 7.3.4 友元再探

### 7.4 [类的作用域](./Chapter7_%E7%B1%BB/note/note_7.4.md)

#### 7.4.1 名字查找与类的作用域

### 7.5 [构造函数再探](./Chapter7_%E7%B1%BB/note/note_7.5.md)

#### 7.5.1 构造函数初始值列表

#### 7.5.2 委托构造函数

#### 7.5.3 默认构造函数的作用

#### 7.5.4 隐式的类类型转换

#### 7.5.5 聚合类

#### 7.5.6 字面值常量类

### 7.6 [类的静态成员](./Chapter7_%E7%B1%BB/note/note_7.6.md)

## 第 8 章 IO库

### 8.1 [IO 类](./Chapter8_IO%E5%BA%93/note/note_8.1.md)

#### 8.1.1 IO 类型无拷贝或赋值

#### 8.1.2 条件状态

#### 8.1.3 管理输出缓冲

### 8.2 [文件输入输出](./Chapter8_IO%E5%BA%93/note/note_8.2.md)

#### 8.2.1 使用文件流对象

#### 8.2.2 文件模式

### 8.3 [string 流](./Chapter8_IO%E5%BA%93/note/note_8.3.md)

#### 8.3.1 使用 istringstream

#### 8.3.2 使用 ostringstream

## 第 9 章 顺序容器

### 9.1 [顺序容器概述](./Chapter9_%E9%A1%BA%E5%BA%8F%E5%AE%B9%E5%99%A8/note/note_9.1.md)

### 9.2 [容器库概览](./Chapter9_%E9%A1%BA%E5%BA%8F%E5%AE%B9%E5%99%A8/note/note_9.2.md)

#### 9.2.1 迭代器

#### 9.2.2 容器类型成员

#### 9.2.3 begin 和 end 成员

#### 9.2.4 容器定义和初始化

#### 9.2.5 赋值和 swap

#### 9.2.6 容器大小操作

#### 9.2.7 关系运算符

### 9.3 [顺序容器操作](./Chapter9_%E9%A1%BA%E5%BA%8F%E5%AE%B9%E5%99%A8/note/note_9.3.md)

#### 9.3.1 向顺序容器添加元素

#### 9.3.2 访问元素

#### 9.3.3 删除元素

#### 9.3.4 特殊的 forward_list 操作

#### 9.3.5 改变容器大小

#### 9.3.6 容器操作可能使迭代器失效

### 9.4 [vector 对象是如何增长的](./Chapter9_%E9%A1%BA%E5%BA%8F%E5%AE%B9%E5%99%A8/note/note_9.4.md)

### 9.5 [额外的 string 操作](./Chapter9_%E9%A1%BA%E5%BA%8F%E5%AE%B9%E5%99%A8/note/note_9.5.md)

#### 9.5.1 构造 string 的其他方法

#### 9.5.2 改变 string 的其他方法

#### 9.5.3 string 搜索操作

#### 9.5.4 compare 函数

#### 9.5.5 数值转换

### 9.6 [容器适配器](./Chapter9_%E9%A1%BA%E5%BA%8F%E5%AE%B9%E5%99%A8/note/note_9.6.md)

## 第 10 章 泛型算法

### 10.1 [概述](./Chapter10_%E6%B3%9B%E5%9E%8B%E7%AE%97%E6%B3%95/note/note_10.1.md)

### 10.2 [初识泛型算法](./Chapter10_%E6%B3%9B%E5%9E%8B%E7%AE%97%E6%B3%95/note/note_10.2.md)

#### 10.2.1 只读算法

#### 10.2.2 写容器元素的算法

#### 10.2.3 重排容器元素的算法

### 10.3 [定制操作](./Chapter10_%E6%B3%9B%E5%9E%8B%E7%AE%97%E6%B3%95/note/note_10.3.md)

#### 10.3.1 向算法传递函数

#### 10.3.2 lambda 表达式

#### 10.3.3 lambda 捕获和返回

#### 10.3.4 参数绑定

### 10.4 [再探迭代器](./Chapter10_%E6%B3%9B%E5%9E%8B%E7%AE%97%E6%B3%95/note/note_10.4.md)

#### 10.4.1 插入迭代器

#### 10.4.2 iostream 迭代器

#### 10.4.3 反向迭代器

### 10.5 [泛型算法结构](./Chapter10_%E6%B3%9B%E5%9E%8B%E7%AE%97%E6%B3%95/note/note_10.5.md)

#### 10.5.1 5 种迭代器

#### 10.5.2 算法形参模式

#### 10.5.3 算法命名规范

### 10.6 [特定容器算法](./Chapter10_%E6%B3%9B%E5%9E%8B%E7%AE%97%E6%B3%95/note/note_10.6.md)

## 第 11 章 关联容器

### 11.1 [使用关联容器](./Chapter11_%E5%85%B3%E8%81%94%E5%AE%B9%E5%99%A8/note/note_11.1.md)

### 11.2 [关联容器概述](./Chapter11_%E5%85%B3%E8%81%94%E5%AE%B9%E5%99%A8/note/note_11.2.md)

#### 11.2.1 定义关联容器

#### 11.2.2 关键字类型的要求

#### 11.2.3 pair 类型

### 11.3 [关联容器操作](./Chapter11_%E5%85%B3%E8%81%94%E5%AE%B9%E5%99%A8/note/note_11.3.md)

#### 11.3.1 关联容器迭代器

#### 11.3.2 添加元素

#### 11.3.3 删除元素

#### 11.3.4 map 的下标操作

#### 11.3.5 访问元素

#### 11.3.6 一个单词转换的 map

### 11.4 [无序容器](./Chapter11_%E5%85%B3%E8%81%94%E5%AE%B9%E5%99%A8/note/note_11.4.md)

## 第 12 章 动态内存

### 12.1 [动态内存与智能指针](./Chapter12_%E5%8A%A8%E6%80%81%E5%86%85%E5%AD%98/note/note_12.1.md)

#### 12.1.1 shared_ptr 类

#### 12.1.2 直接管理内存

#### 12.1.3 shared_ptr 和 new 结合使用

#### 12.1.4 智能指针和异常

#### 12.1.5 unique_ptr

#### 12.1.6 weak_ptr

### 12.2 [动态数组](./Chapter12_%E5%8A%A8%E6%80%81%E5%86%85%E5%AD%98/note/note_12.2.md)

#### 12.2.1 new 和数组

#### 12.2.2 allocator 类

### 12.3 [使用标准库：文本查询程序](./Chapter12_%E5%8A%A8%E6%80%81%E5%86%85%E5%AD%98/note/note_12.3.md)

#### 12.3.1 文本查询程序设计

#### 12.3.2 文本查询程序类的定义

## 第 13 章 拷贝控制

### 13.1 [拷贝、赋值与销毁](./Chapter13_%E6%8B%B7%E8%B4%9D%E6%8E%A7%E5%88%B6/note/note_13.1.md)

#### 13.1.1 拷贝构造函数

#### 13.1.2 拷贝赋值运算符

#### 13.1.3 析构函数

#### 13.1.4 三/五法则

#### 13.1.5 使用=default

#### 13.1.6 阻止拷贝

### 13.2 [拷贝控制和资源管理](./Chapter13_%E6%8B%B7%E8%B4%9D%E6%8E%A7%E5%88%B6/note/note_13.2.md)

#### 13.2.1 行为像值的类

#### 13.2.2 定义行为像指针的类

### 13.3 [交换操作](./Chapter13_%E6%8B%B7%E8%B4%9D%E6%8E%A7%E5%88%B6/note/note_13.3.md)

### 13.4 [拷贝控制示例](./Chapter13_%E6%8B%B7%E8%B4%9D%E6%8E%A7%E5%88%B6/note/note_13.4.md)

### 13.5 [动态内存管理类](./Chapter13_%E6%8B%B7%E8%B4%9D%E6%8E%A7%E5%88%B6/note/note_13.5.md)

### 13.6 [对象移动](./Chapter13_%E6%8B%B7%E8%B4%9D%E6%8E%A7%E5%88%B6/note/note_13.6.md)

#### 13.6.1 右值引用

#### 13.6.2 移动构造函数和移动赋值运算符

#### 13.6.3 右值引用和成员函数

## 第 14 章 重载运算与类型转换

### 14.1 [基本概念](./Chapter14_%E9%87%8D%E8%BD%BD%E8%BF%90%E7%AE%97%E4%B8%8E%E7%B1%BB%E5%9E%8B%E8%BD%AC%E6%8D%A2/note/note_14.1.md)

### 14.2 [输入和输出运算符](./Chapter14_%E9%87%8D%E8%BD%BD%E8%BF%90%E7%AE%97%E4%B8%8E%E7%B1%BB%E5%9E%8B%E8%BD%AC%E6%8D%A2/note/note_14.2.md)

#### 14.2.1 重载输出运算符 `<<`

#### 14.2.2 重载输入运算符 `>>`

### 14.3 [算术和关系运算符](./Chapter14_%E9%87%8D%E8%BD%BD%E8%BF%90%E7%AE%97%E4%B8%8E%E7%B1%BB%E5%9E%8B%E8%BD%AC%E6%8D%A2/note/note_14.3.md)

#### 14.3.1 相等运算符

#### 14.3.2 关系运算符

### 14.4 [赋值运算符](./Chapter14_%E9%87%8D%E8%BD%BD%E8%BF%90%E7%AE%97%E4%B8%8E%E7%B1%BB%E5%9E%8B%E8%BD%AC%E6%8D%A2/note/note_14.4.md)

### 14.5 [下标运算符](./Chapter14_%E9%87%8D%E8%BD%BD%E8%BF%90%E7%AE%97%E4%B8%8E%E7%B1%BB%E5%9E%8B%E8%BD%AC%E6%8D%A2/note/note_14.5.md)

### 14.6 [递增和递减运算符](./Chapter14_%E9%87%8D%E8%BD%BD%E8%BF%90%E7%AE%97%E4%B8%8E%E7%B1%BB%E5%9E%8B%E8%BD%AC%E6%8D%A2/note/note_14.6.md)

### 14.7 [成员访问运算符](./Chapter14_%E9%87%8D%E8%BD%BD%E8%BF%90%E7%AE%97%E4%B8%8E%E7%B1%BB%E5%9E%8B%E8%BD%AC%E6%8D%A2/note/note_14.7.md)

### 14.8 [函数调用运算符](./Chapter14_%E9%87%8D%E8%BD%BD%E8%BF%90%E7%AE%97%E4%B8%8E%E7%B1%BB%E5%9E%8B%E8%BD%AC%E6%8D%A2/note/note_14.8.md)

#### 14.8.1 lambda 是函数对象

#### 14.8.2 标准库定义的函数对象

#### 14.8.3 可调用对象与 function

### 14.9 [重载、类型转换与运算符](./Chapter14_%E9%87%8D%E8%BD%BD%E8%BF%90%E7%AE%97%E4%B8%8E%E7%B1%BB%E5%9E%8B%E8%BD%AC%E6%8D%A2/note/note_14.9.md)

#### 14.9.1 类型转换运算符

#### 14.9.2 避免有二义性的类型转换

#### 14.9.3 函数匹配与重载运算符

## 第 15 章 面向对象程序设计

### 15.1 [OOP：概述](./Chapter15_%E9%9D%A2%E5%90%91%E5%AF%B9%E8%B1%A1%E7%A8%8B%E5%BA%8F%E8%AE%BE%E8%AE%A1/note/note_15.1.md)

### 15.2 [定义基类和派生类](./Chapter15_%E9%9D%A2%E5%90%91%E5%AF%B9%E8%B1%A1%E7%A8%8B%E5%BA%8F%E8%AE%BE%E8%AE%A1/note/note_15.2.md)

#### 15.2.1 定义基类

#### 15.2.2 定义派生类

#### 15.2.3 类型转换与继承

### 15.3 [虚函数](./Chapter15_%E9%9D%A2%E5%90%91%E5%AF%B9%E8%B1%A1%E7%A8%8B%E5%BA%8F%E8%AE%BE%E8%AE%A1/note/note_15.3.md)

### 15.4 [抽象基类](./Chapter15_%E9%9D%A2%E5%90%91%E5%AF%B9%E8%B1%A1%E7%A8%8B%E5%BA%8F%E8%AE%BE%E8%AE%A1/note/note_15.4.md)

### 15.5 [访问控制与继承](./Chapter15_%E9%9D%A2%E5%90%91%E5%AF%B9%E8%B1%A1%E7%A8%8B%E5%BA%8F%E8%AE%BE%E8%AE%A1/note/note_15.5.md)

### 15.6 [继承中的类作用域](./Chapter15_%E9%9D%A2%E5%90%91%E5%AF%B9%E8%B1%A1%E7%A8%8B%E5%BA%8F%E8%AE%BE%E8%AE%A1/note/note_15.6.md)

### 15.7 [构造函数与拷贝控制](./Chapter15_%E9%9D%A2%E5%90%91%E5%AF%B9%E8%B1%A1%E7%A8%8B%E5%BA%8F%E8%AE%BE%E8%AE%A1/note/note_15.7.md)

#### 15.7.1 虚析构函数

#### 15.7.2 合成拷贝控制与继承

#### 15.7.3 派生类的拷贝控制成员

#### 15.7.4 继承的构造函数

### 15.8 [容器与继承](./Chapter15_%E9%9D%A2%E5%90%91%E5%AF%B9%E8%B1%A1%E7%A8%8B%E5%BA%8F%E8%AE%BE%E8%AE%A1/note/note_15.8.md)

#### 15.8.1 编写 Basket 类

### 15.9 [文本查询程序再探](./Chapter15_%E9%9D%A2%E5%90%91%E5%AF%B9%E8%B1%A1%E7%A8%8B%E5%BA%8F%E8%AE%BE%E8%AE%A1/note/note_15.9.md)

#### 15.9.1 面向对象的解决方案

#### 15.9.2 Query_base 类和 Query 类

#### 15.9.3 派生类

#### 15.9.4 eval 函数

## 第 16 章 模板与泛型编程

### 16.1 [定义模板](./Chapter16_%E6%A8%A1%E6%9D%BF%E4%B8%8E%E6%B3%9B%E5%9E%8B%E7%BC%96%E7%A8%8B/note/note_16.1.md)

#### 16.1.1 函数模板

#### 16.1.2 类模板

#### 16.1.3 模板参数

#### 16.1.4 成员模板

#### 16.1.5 控制实例化

#### 16.1.6 效率与灵活性

### 16.2 [模板实参推断](./Chapter16_%E6%A8%A1%E6%9D%BF%E4%B8%8E%E6%B3%9B%E5%9E%8B%E7%BC%96%E7%A8%8B/note/note_16.2.md)

#### 16.2.1 类型转换与模板类型参数

#### 16.2.2 函数模板显式实参

#### 16.2.3 尾置返回类型和类型转换

#### 16.2.4 函数指针和实参推断

#### 16.2.5 模板实参推断和引用

#### 16.2.6 理解 std::move

#### 16.2.7 转发

### 16.3 [重载与模板](./Chapter16_%E6%A8%A1%E6%9D%BF%E4%B8%8E%E6%B3%9B%E5%9E%8B%E7%BC%96%E7%A8%8B/note/note_16.3.md)

### 16.4 [可变参数模板](./Chapter16_%E6%A8%A1%E6%9D%BF%E4%B8%8E%E6%B3%9B%E5%9E%8B%E7%BC%96%E7%A8%8B/note/note_16.4.md)

#### 16.4.1 编写可变参数函数模板

#### 16.4.2 包扩展

#### 16.4.3 转发参数包

### 16.5 [模板特例化](./Chapter16_%E6%A8%A1%E6%9D%BF%E4%B8%8E%E6%B3%9B%E5%9E%8B%E7%BC%96%E7%A8%8B/note/note_16.5.md)

## 第 17 章 标准库特殊设施

### 17.1 [tuple 类型](./Chapter17_%E6%A0%87%E5%87%86%E5%BA%93%E7%89%B9%E6%AE%8A%E8%AE%BE%E6%96%BD/note/note_17.1.md)

#### 17.1.1 定义和初始化 tuple

#### 17.1.2 使用 tuple 返回多个值

### 17.2 [bitset 类型](./Chapter17_%E6%A0%87%E5%87%86%E5%BA%93%E7%89%B9%E6%AE%8A%E8%AE%BE%E6%96%BD/note/note_17.2.md)

#### 17.2.1 定义和初始化 bitset

#### 17.2.2 bitset 操作

### 17.3 [正则表达式](./Chapter17_%E6%A0%87%E5%87%86%E5%BA%93%E7%89%B9%E6%AE%8A%E8%AE%BE%E6%96%BD/note/note_17.3.md)

#### 17.3.1 使用正则表达式库

#### 17.3.2 匹配与 Regex 迭代器类型

#### 17.3.3 使用子表达式

#### 17.3.4 使用 regex_replace

### 17.4 [随机数](./Chapter17_%E6%A0%87%E5%87%86%E5%BA%93%E7%89%B9%E6%AE%8A%E8%AE%BE%E6%96%BD/note/note_17.4.md)

#### 17.4.1 随机数引擎和分布

#### 17.4.2 其他随机数分布

### 17.5 [IO 库再探](./Chapter17_%E6%A0%87%E5%87%86%E5%BA%93%E7%89%B9%E6%AE%8A%E8%AE%BE%E6%96%BD/note/note_17.5.md)

#### 17.5.1 格式化输入与输出

#### 17.5.2 未格式化的输入/输出操作

#### 17.5.3 流随机访问

## 第 18 章 用于大型程序的工具

### 18.1 [异常处理](./Chapter18_%E7%94%A8%E4%BA%8E%E5%A4%A7%E5%9E%8B%E7%A8%8B%E5%BA%8F%E7%9A%84%E5%B7%A5%E5%85%B7/note/note_18.1.md)

#### 18.1.1 抛出异常

#### 18.1.2 捕获异常

#### 18.1.3 函数 try 语句块与构造函数

#### 18.1.4 异常类层次

### 18.2 [命名空间](./Chapter18_%E7%94%A8%E4%BA%8E%E5%A4%A7%E5%9E%8B%E7%A8%8B%E5%BA%8F%E7%9A%84%E5%B7%A5%E5%85%B7/note/note_18.2.md)

#### 18.2.1 命名空间定义

#### 18.2.2 使用命名空间成员

#### 18.2.3 类、命名空间与作用域

#### 18.2.4 重载与命名空间

### 18.3 [多重继承与虚继承](./Chapter18_%E7%94%A8%E4%BA%8E%E5%A4%A7%E5%9E%8B%E7%A8%8B%E5%BA%8F%E7%9A%84%E5%B7%A5%E5%85%B7/note/note_18.3.md)

#### 18.3.1 多重继承

#### 18.3.2 类型转换与多个基类

#### 18.3.3 多重继承下的类作用域

#### 18.3.4 虚继承

#### 18.3.5 构造函数与虚继承

## 第 19 章 特殊工具与技术

### 19.1 [控制内存分配](./Chapter19_%E7%89%B9%E6%AE%8A%E5%B7%A5%E5%85%B7%E4%B8%8E%E6%8A%80%E6%9C%AF/note/note_19.1.md)

#### 19.1.1 重载 new 和 delete

#### 19.1.2 定位 new 表达式

### 19.2 [运行时类型识别](./Chapter19_%E7%89%B9%E6%AE%8A%E5%B7%A5%E5%85%B7%E4%B8%8E%E6%8A%80%E6%9C%AF/note/note_19.2.md)

#### 19.2.1 dynamic_cast 运算符

#### 19.2.2 typeid 运算符

#### 19.2.3 使用 RTTI

#### 19.2.4 type_info 类

### 19.3 [枚举类型](./Chapter19_%E7%89%B9%E6%AE%8A%E5%B7%A5%E5%85%B7%E4%B8%8E%E6%8A%80%E6%9C%AF/note/note_19.3.md)

### 19.4 [类成员指针](./Chapter19_%E7%89%B9%E6%AE%8A%E5%B7%A5%E5%85%B7%E4%B8%8E%E6%8A%80%E6%9C%AF/note/note_19.4.md)

#### 19.4.1 数据成员指针

#### 19.4.2 成员函数指针

#### 19.4.3 将成员函数用作可调用对象

### 19.5 [嵌套类](./Chapter19_%E7%89%B9%E6%AE%8A%E5%B7%A5%E5%85%B7%E4%B8%8E%E6%8A%80%E6%9C%AF/note/note_19.5.md)

### 19.6 [union ：一种节省空间的类](./Chapter19_%E7%89%B9%E6%AE%8A%E5%B7%A5%E5%85%B7%E4%B8%8E%E6%8A%80%E6%9C%AF/note/note_19.6.md)

### 19.7 [局部类](./Chapter19_%E7%89%B9%E6%AE%8A%E5%B7%A5%E5%85%B7%E4%B8%8E%E6%8A%80%E6%9C%AF/note/note_19.7.md)

### 19.8 [固有的不可移植的特性](./Chapter19_%E7%89%B9%E6%AE%8A%E5%B7%A5%E5%85%B7%E4%B8%8E%E6%8A%80%E6%9C%AF/note/note_19.8.md)

#### 19.8.1 位域

#### 19.8.2 violate 限定符

#### 19.8.3 链接指示：`extern "C"`

## 附录 A 标准库

### A.1 [标准库名字和头文件](./AppendixA_%E6%A0%87%E5%87%86%E5%BA%93/A.1_%E6%A0%87%E5%87%86%E5%BA%93%E5%90%8D%E5%AD%97%E5%92%8C%E5%A4%B4%E6%96%87%E4%BB%B6.md)

### A.2 [算法概览](./AppendixA_%E6%A0%87%E5%87%86%E5%BA%93/A.2_%E7%AE%97%E6%B3%95%E6%A6%82%E8%A7%88.md)

### A.3 [随机数](./AppendixA_%E6%A0%87%E5%87%86%E5%BA%93/A.3_%E9%9A%8F%E6%9C%BA%E6%95%B0.md)

## 待办事项

* 为附录 [A.2](./AppendixA_%E6%A0%87%E5%87%86%E5%BA%93/A.2_%E7%AE%97%E6%B3%95%E6%A6%82%E8%A7%88.md) 和 [A.3](./AppendixA_%E6%A0%87%E5%87%86%E5%BA%93/A.3_%E9%9A%8F%E6%9C%BA%E6%95%B0.md) 增加内容

## 遵守协议

<p xmlns:cc="http://creativecommons.org/ns#" xmlns:dct="http://purl.org/dc/terms/"><a property="dct:title" rel="cc:attributionURL" href="https://github.com/liuzhaoze/cpp-primer-answer">C++ Primer 中文版：第 5 版 读书笔记/课后练习</a> by <a rel="cc:attributionURL dct:creator" property="cc:attributionName" href="https://github.com/liuzhaoze">Zhaoze Liu</a> is licensed under <a href="http://creativecommons.org/licenses/by-nc-sa/4.0/?ref=chooser-v1" target="_blank" rel="license noopener noreferrer" style="display:inline-block;">CC BY-NC-SA 4.0<img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/cc.svg?ref=chooser-v1"><img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/by.svg?ref=chooser-v1"><img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/nc.svg?ref=chooser-v1"><img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/sa.svg?ref=chooser-v1"></a></p>
