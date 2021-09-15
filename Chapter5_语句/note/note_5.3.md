## 5.3 条件语句

### 5.3.1 if 语句
else 与离它最近的尚未匹配的 if 匹配。

### 5.3.2 switch 语句
case 标签必须是整型常量表达式。

如果表达式和某个 case 标签的值匹配成功，程序从该标签之后的第一条语句开始执行，直到到达了 switch 的结尾或者是遇到一条 break 语句为止。

*一般不要省略 case 分支最后的 break 语句。如果没写 break 语句，最好加一段注释说清楚程序的逻辑。*

即使不准备在 default 标签下做任何工作，也应该定义一个 default 标签。如果 switch 结构以一个空的 default 标签作为结束，则该 default 标签后面必须跟上一条空语句或一个空块。

如果需要为某个 case 分支定义并初始化一个变量，应该把变量定义在块内，从而确保后面的所有 case 标签都在变量的作用域之外。
```c
switch (isFile) {
    case true:
        {
            string file_name = get_file_name();
            // ...
        }
        break;
    case false:
        // ...
    default:
        // ...
}
```

### 练习
* [练习 5.5](../src/quiz_5.5.cpp)
* [练习 5.6](../src/quiz_5.6.cpp)
* [练习 5.7](../src/quiz_5.7.cpp)
* [练习 5.8](../src/quiz_5.8.md)
* [练习 5.9](../src/quiz_5.9.cpp)
* [练习 5.10](../src/quiz_5.10.cpp)
* [练习 5.11](../src/quiz_5.11.cpp)
* [练习 5.12](../src/quiz_5.12.cpp)
* [练习 5.13](../src/quiz_5.13.cpp)
