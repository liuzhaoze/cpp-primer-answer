# 5.4 迭代语句

## 5.4.1 while 语句

定义在 while 条件部分或者 while 循环体内的变量每次迭代都经历**从创建到销毁**的过程。

当不确定到底迭代多少次时，使用 while 循环比较合适，如：读取输入的内容。

## 5.4.2 传统的 for 语句

```c
for (init-statement; condition; expression)
    statement
```

for 语句头中定义的对象只在 for 循环体内可见。  
init-statement 可以定义多个对象，但是所有对象的类型必须相同。  
省略 condition 的效果等价于在条件部分写了一个 true 。

## 5.4.3 范围 for 语句

```c
for (declaration : expression)
    statement
```

expression 必须是一个序列：用花括号括起来的初始值列表、数组、vector、string（能返回迭代器的 begin 和 end 成员）

如果需要对序列中的元素执行写操作，循环变量 declaration 必须声明成引用类型。

*范围 for 语句体内不应改变其所遍历序列的大小。*

## 5.4.4 do while 语句

```c
do
    statement
while (condition);
```

condition 使用的变量必须定义在循环体之外。  
不允许在条件部分定义变量。

## 练习

* [练习 5.14](../src/quiz_5.14.cpp)
* [练习 5.15](../src/quiz_5.15.md)
* [练习 5.16](../src/quiz_5.16.md)
* [练习 5.17](../src/quiz_5.17.cpp)
* [练习 5.18](../src/quiz_5.18.md)
* [练习 5.19]
