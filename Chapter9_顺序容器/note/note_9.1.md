# 9.1 顺序容器概述

顺序容器类型：

* `vector` ：可变大小数组
* `array` ：固定大小数组
* `deque` ：双端队列
* `list` ：双向链表
* `forward_list` ：单向链表
* `string` ：专门用于保存字符的 vector

选择容器的基本原则：

* 随机访问使用 vector 或 deque
* 在中间插入或删除元素使用 list 或 forward_list
* 在头尾插入或删除元素使用 deque

## 练习

* [练习 9.1](../src/quiz_9.1.md)
