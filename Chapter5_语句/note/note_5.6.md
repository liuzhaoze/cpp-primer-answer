# 5.6 try 语句块和异常处理

> 本章术语：
>  
> * throw 表达式（throw expression）：使用 throw 表达式引发（rise）异常
> * try 语句块（try block）：try 语句块中的代码会引发异常
> * catch 子句（catch clause）/ 异常处理代码（exception handler）：处理异常
> * 异常类（exception class）：用于在 throw 表达式和相关的 catch 子句传递异常的具体信息。
> * 异常安全（exception safe）的代码：在异常发生期间正确执行了“清理”工作的程序。

## 5.6.1 throw 表达式

抛出异常将终止当前的函数，并把控制权转移给能处理该异常的代码。

## 5.6.2 try 语句块

```c
try {
    program-statements
} catch (exception-declaration) {
    handler-statements
} catch (exception-declaration) {
    handler-statements
}
```

try 语句块内声明的变量在块外部无法访问，特别是在 catch 子句内也无法访问。

当异常被抛出时，首先搜索抛出该异常的函数。如果没有找到匹配的 catch 子句，则终止该函数，并在调用该函数的函数中继续寻找。  
以此类推，沿着程序的执行路径逐层回退，直到找到适当类型的 catch 子句为之。

如果最终还是没能找到任何匹配的 catch 子句，程序转到名为 terminate 的标准库函数中。一般情况下，执行该函数将导致程序非正常退出。

## 5.6.3 标准异常

* exception 头文件定义了最通用的异常类 exception 。它只报告异常的发生，不提供任何额外信息。
* stdexcept 头文件定义了几种常用的异常类。
* new 头文件定义了 bad_alloc 异常类型。
* type_info 头文件定义了 bad_cast 异常类型。

stdexcept 定义的异常类
|类名|含义|
|:-:|:-|
|exception|最常见的问题|
|runtime_error|只有在运行时才能检测出的问题|
|range_error|运行时错误：生成的结果超出了有意义的值域范围|
|overflow_error|运行时错误：计算上溢|
|underflow_error|运行时错误：计算下溢|
|logic_error|程序逻辑错误|
|domain_error|逻辑错误：参数对应的结果值不存在|
|invalid_argument|逻辑错误：无效参数|
|length_error|逻辑错误：试图创建一个超出该类型最大长度的对象|
|out_of_range|逻辑错误：使用一个超出有效范围的值|

只能以默认初始化的方式初始化 exception 、 bad_alloc 和 bad_cast 对象，不允许为这些对象提供初始值。

应该使用 string 对象或者 C 风格字符串初始化其他异常类型，但是不允许使用默认初始化的方式。字符串含有错误相关的信息。

异常类型只定义了一个名为 what 的成员函数。如果异常类型有一个字符串初始值，则 what 返回该字符串。对于其他无初始值的异常类型， what 返回的内容由编译器决定。

## 练习

* [练习 5.23](../src/quiz_5.23.cpp)
* [练习 5.24](../src/quiz_5.24.cpp)
* [练习 5.25](../src/quiz_5.25.cpp)
