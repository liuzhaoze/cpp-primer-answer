# 12.3 使用标准库：文本查询程序

## 12.3.1 文本查询程序设计

需要完成的任务：

* 逐行读取输入文件，并将每一行分解为独立的单词
* 程序需要输出的内容
  * 每个单词所关联的行号
  * 行号按升序出现且无重复
  * 必须能打印给定行号中的文本

实现方法：

* 使用 `vector<string>` 储存每一行文本：用行号作为下标提取行文本
* 使用 `istringstream` 分解每一行的单词
* 使用 `set` 保存一个单词在整个文本中出现的行号：每行只出现一次且按升序保存
* 使用 `map` 将每个单词与对应的行号 set 关联起来

数据结构：

* TextQuery 类
  * 数据成员：
    * `vector<string>`
    * `map`
  * 方法：
    * 读取给定输入文件的构造函数
    * 查询：返回指定单词出现了多少次、出现的行号以及每行的文本
* QueryResult 类
  * TextQuery 类的查询方法应当返回的对象
  * 方法：
    * print 打印结果

使用 shared_ptr 实现两个类之间的数据共享。

*在设计一个类时，应该先编写程序使用这个类。根据程序需要的操作来编写类的成员。*

## 12.3.2 文本查询程序类的定义

见[练习 12.27](../src/quiz_12.27.hpp) hpp 和 cpp 文件。

## 练习

* [练习 12.27](../src/quiz_12.27.hpp)
* [练习 12.28](../src/quiz_12.28.cpp)
* [练习 12.29](../src/quiz_12.29.cpp)
* [练习 12.30](../src/quiz_12.30.cpp)
* [练习 12.31](../src/quiz_12.31.md)
* [练习 12.32](../src/quiz_12.32.hpp)
* [练习 12.33](../src/quiz_12.33.hpp)
