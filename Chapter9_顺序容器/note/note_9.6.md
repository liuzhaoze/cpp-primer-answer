# 9.6 容器适配器

> 本章术语：
>
> * 适配器（adaptor）：使某种事物的行为看起来像另外一种事物

标准库定义了三个顺序容器适配器：`stack` 、 `queue` 和 `priority_queue` 。

所有容器适配器都支持的操作和类型：

* `size_type` ：足以保存当前类型的最大对象的大小的无符号整型
* `value_type` ：元素类型
* `container_type` ：实现适配器的底层容器的类型
* `A a;` ：创建一个名为 a 的空适配器
* `A a(c);` ：创建一个名为 a 的适配器，其内容是容器 c 的一个拷贝
* 关系运算符 `==` `!=` `<` `<=` `>` `>=` ：返回底层容器的比较结果
* `a.empty()` ：如果 a 是空适配器，返回 true ，否则返回 false
* `a.size()` ：返回 a 中的元素数目
* `swap(a, b)` ：交换 a 和 b 的内容，a 和 b 必须具有相同的类型，底层容器类型也必须相同
* `a.swap(b)` ：交换 a 和 b 的内容，a 和 b 必须具有相同的类型，底层容器类型也必须相同

对于给定的适配器，可以使用的底层容器类型是有限制的：  
`√` 为可用，`×` 为不可用。
|适配器类型|vector|deque|list|forward_list|array|
|:-:|:-:|:-:|:-:|:-:|:-:|
|stack|√|√（默认）|√|×|×|
|queue|×|√（默认）|√|×|×|
|priority_queue|√（默认）|√|×|×|×|

* 适配器大小可变，不能使用 array
* 适配器要求能够操作尾元素，不能使用 forward_list
* vector 不支持向首部插入元素，不能作为 queue 的底层容器
* priority_queue 要求随机访问能力，不能使用 list

```cpp
deque<int> deq = { ... };
stack<int> stk(deq); // 使用 deq 的拷贝初始化适配器 stk

stack<string, vector<string>> str_stk; // 使用第二个类型参数指定适配器的底层容器类型为 vector
```

只能使用适配器具有的操作，不能使用底层容器类型具有的操作。

**栈适配器**特有的操作（定义在 stack 头文件中）：

* `s.pop()` ：删除栈顶元素，但不返回该元素值
* `s.push(item)` ：将元素 item 压入栈顶
* `s.emplace(args)` ：使用参数列表 args 构造一个元素并压入栈顶
* `s.top()` ：返回栈顶元素，但不将元素弹出栈

**队列适配器**特有的操作（定义在 queue 头文件中）：

* `q.pop()` ：删除 queue 的首元素或 priority_queue 优先级最高的元素，但不返回该元素
* `q.front()` ：返回首元素，但不删除该元素
* `q.back()` ：返回尾元素，但不删除该元素（只适用于 queue ，不适用于 priority_queue ）
* `q.top()` ：返回优先级最高的元素，但不删除该元素（只适用于 priority_queue ，不适用于 queue ）
* `q.push(item)` ：在 queue 的末尾或 priority_queue 的适当位置插入元素 item
* `q.emplace(args)` ：使用参数列表 args 在 queue 的末尾或 priority_queue 的适当位置创建新元素

`priority_queue` 的元素具有优先级。新加入的元素会排在所有比它优先级低的元素之前。  
标准库默认在元素类型上使用 `<` 运算符来确定元素的相对优先级。

## 练习

* [练习 9.52](../src/quiz_9.52.cpp)
