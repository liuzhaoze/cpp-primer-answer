## 1.4 控制流

### while 语句
```c
while (condition)
    statement
```

### for 语句
```c
for (init-statement; condition; expression)
    statement
```
在初始化语句（init-statement）中定义的变量只能在循环内部使用，
在循环结束之后无法使用。

初始化语句只在 for 循环入口处执行一次。  
循环体每次执行前都会检查循环条件（condition）。  
表达式（expression）在 for 循环体之后执行。

### 读取数量不定的输入数据
使用：
```c
while (std::cin >> value)
```
当我们使用一个 istream 对象最为条件时，其效果是检测流的状态。
如果流是有效的，即流未遇到错误，那么检测成功，条件为真。
当遇到文件结束符（end-of-file），或遇到一个无效输入时（例如读入的值不是一个整数），
istream 对象的状态会变为无效。处于无效状态的 istream 对象会使条件变为假。

### 从键盘输入文件结束符 EOF
* Windows 系统： Ctrl+Z ， Enter
* UNIX 系统： Ctrl+D

### 练习
* [练习 1.9](../src/quiz_1.9.cpp)
* [练习 1.10](../src/quiz_1.10.cpp)
* [练习 1.11](../src/quiz_1.11.cpp)
* [练习 1.12](../src/quiz_1.12.cpp)
* [练习 1.13](../src/quiz_1.13.cpp)
* [练习 1.14](../src/quiz_1.14.md)
* [练习 1.16](../src/quiz_1.16.cpp)
* [练习 1.18](../src/quiz_1.18.cpp)
* 练习 1.19：程序中已完成
