# 9.3 顺序容器操作

顺序容器特有的操作：

## 9.3.1 向顺序容器添加元素

**除 array 以外**的顺序容器都可以在运行时动态添加或删除元素。  
forward_list 的 insert 和 emplace 接口名与下面不同。  
forward_list 不支持 push_back 和 emplace_back 。  
vector 和 string 不支持 push_front 和 emplace_front 。

* `c.push_back(t)` ：在 c 的尾部添加一个值为 t 的元素，返回 void
* `c.emplace_back(args)` ：在 c 的尾部添加一个由 args 参数创建的元素，返回 void
* `c.push_front(t)` ：在 c 的头部添加一个值为 t 的元素，返回 void
* `c.emplace_front(args)` ：在 c 的头部添加一个由 args 参数创建的元素，返回 void
* `c.insert(p, t)` ：在迭代器 p 指向的元素**之前**插入一个值为 t 的元素，返回指向新添加的元素的迭代器
* `c.emplace(p, args)` ：在迭代器 p 指向的元素**之前**插入一个由 args 参数创建的元素，返回指向新添加的元素的迭代器
* `c.insert(p, n, t)` ：在迭代器 p 指向的元素**之前**插入 n 个值为 t 的元素，返回指向新添加的第一个元素的迭代器（若 n 为 0 ，则返回 p ）
* `c.insert(p, b, e)` ：将迭代器 b 和 e 指定的范围内的元素插入到迭代器 p 指向的元素**之前**，返回指向新添加的第一个元素的迭代器（若范围为空，则返回 p ；b 和 e 不能指向 c 中的元素）
* `c.insert(p, il)` ：将花括号包围的元素值列表 il 插入到迭代器 p 指向的元素**之前**，返回指向新添加的第一个元素的迭代器（若列表为空，则返回 p ）

*向 vector 、 string 或 deque 中插入元素会使所有指向该容器的迭代器、引用和指针失效。*

*容器中的元素是对象的拷贝，而不是对象本身。*

*emplace 函数的参数必须与元素类型的构造函数相匹配。*

> * push_back
>   * 除了 array 和 forward_list 之外，每个顺序容器都支持 push_back 操作。
> * push_front
>   * list 、 forward_list 和 deque 容器支持 push_front 操作。
> * insert
>   * vector 、 deque 、 list 和 string 支持 insert 操作。insert 操作的 p 参数可以指向尾后元素。
> * emplace
>   * 调用 push 或 insert 时，将要插入的对象拷贝到容器中；调用 emplace 时，将参数传递给对象的构造函数，在容器内存空间中直接创建对象。

可以使用 insert 的返回值，可以在容器中一个特定位置反复插入元素。例：

```cpp
list<string> lst;
auto iter = lst.begin();
while (cin >> word)
    iter = lst.insert(iter, word); // 始终将读入的 word 插入 lst 的开头
```

push_back 和 emplace_back 的区别：

```cpp
c.push_back(Sales_data("978-0590353402", 25, 19.99)); // 创建了一个 Sales_data 对象，将其拷贝到 c 中
c.emplace_back("978-0590353402", 25, 19.99); // 直接把三个 Sales_data 的参数传递给 emplace_back ，由 emplace_back 在 c 的内存中直接创建对象
```

## 9.3.2 访问元素

包括 array 在内的每个顺序容器都有一个 front 成员函数。  
除 forward_list 之外的所有顺序容器都有一个 back 成员函数。  
at 和下标操作只适用于 string 、 vector 、 deque 和 array。

* `c.back()` ：返回 c 中尾元素的引用（ c 为空时函数行为未定义）
* `c.front()` ：返回 c 中首元素的引用（ c 为空时函数行为未定义）
* `c[n]` ：返回 c 中下标为 n 的元素的引用（ n 是无符号整数）（下标越界时函数行为未定义）
* `c.at(n)` ：返回下标为 n 的元素的引用（下标越界时抛出 out_of_range 异常）

```cpp
auto v1 = c.back(); // v1 不是引用，是 c.back() 的一个拷贝
auto &v2 = c.back(); // v2 是指向最后一个元素的引用
// 可以通过 v2 修改 c 中最后一个元素的值
// 但是 v1 不行
```

为了确保下标是合法的，应当使用 at 成员函数。

## 9.3.3 删除元素

顺序容器的删除操作：

* `c.pop_back()` ：删除 c 中尾元素，返回 void（ c 为空时函数行为未定义）
* `c.pop_front()` ：删除 c 中首元素，返回 void（ c 为空时函数行为未定义）
* `c.erase(p)` ：删除迭代器 p 所指定的元素，返回指向被删元素之后元素的迭代器；当 p 指向尾元素时，返回尾后迭代器（ p 为尾后迭代器时函数行为未定义）
* `c.erase(b, e)` ：删除迭代器 b 、e 所指定范围内的元素，返回指向最后一个被删元素之后元素的迭代器；当 e 是尾后迭代器时，同样返回尾后迭代器
* `c.clear()` ：删除 c 中所有元素，返回 void

array 不适用于上述操作。  
forward_list 有特殊版本的 erase ，且不支持 pop_back 。
vector 和 string 不支持 pop_front 。

*注：删除 deque 中除首尾位置之外的任何元素都会使所有迭代器、引用和指针失效。*  
*注：指向 vector 或 string 中删除点之后位置的迭代器、引用和指针都会失效。*

*注：删除元素的成员函数并不检查其参数。在删除元素之前，必须确保要删除的元素是存在的。*

```cpp
// 例：循环删除容器中的所有奇数
list<int> lst = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
auto iter = lst.begin();

while(iter != lst.end()) {
    if (*iter % 2) // 当前元素为奇数
        iter = lst.erase(iter) // 删除元素并且迭代器后移
    else
        ++iter; // 当前元素为偶数，直接迭代器后移
}
```

## 9.3.4 特殊的 forward_list 操作

对于单向链表，添加或删除一个元素需要修改前驱元素的指针。所以 forward_list 的操作与其他容器不同：

* 首前迭代器：
  * `lst.before_begin()` ：返回单向链表的首前迭代器，指向第一个元素之前的位置
  * `lst.cbefore_begin()` ：返回 const_iterator ，位置同上
* 插入操作：
  * `lst.insert_after(p, t)` ：在迭代器 p 之后插入元素 t
  * `lst.insert_after(p, n, t)` ：在迭代器 p 之后插入 n 个元素 t
  * `lst.insert_after(p, b, e)` ：在迭代器 p 之后插入 b 、e 迭代器范围中的元素（b 、e 不能指向 lst 内）
  * `lst.insert_after(p, il)` ：在迭代器 p 之后插入花括号列表 il 中的元素
  * 上述插入操作返回指向最后一个插入元素的迭代器；若范围为空，则返回 p ；若 p 为尾后迭代器，则插入函数行为未定义
  * `emplace_after(p, args)` ：使用参数 args 在迭代器 p 之后创建一个元素，返回指向新元素的迭代器（若 p 为尾后迭代器，，则插入函数行为未定义）
* 删除操作：
  * `lst.erase_after(p)` ：删除迭代器 p 之后的元素
  * `lst.erase_after(b, e)` ：删除从 b 之后的元素开始，到 e 之前的元素结束，这个范围内的元素（ b 不删，e 不删）
  * 上述删除操作返回指向被删元素之后元素的迭代器，若不存在这样的元素，则返回尾后迭代器（若 p 指向 lst 的尾元素或尾后元素，则函数行为未定义）

## 9.3.5 改变容器大小

改变顺序容器的大小：

* `c.resize(n)` ：将容器 c 的大小调整为 n
* `c.resize(n, t)` ：将容器 c 的大小调整为 n ，新添加的元素都初始化为 t

array 不支持 resize 。  
若 c.size() > n ，则容器尾部多出的元素会被丢弃；  
若 c.size() < n ，则新增加的尾部元素进行值初始化。

*注：如果 resize 缩小容器，则指向被删除元素的迭代器、引用和指针都会失效；对 vector 、string 或 deque 进行 resize 可能导致迭代器、指针和引用失效。*

## 9.3.6 容器操作可能使迭代器失效

* 向容器中添加元素
  * 对于 vector 和 string ：如果存储空间被重新分配，则指向容器的迭代器、指针和引用都会失效；如果存储空间未重新分配，则指向插入位置**之前**的元素的迭代器、指针和引用仍有效，但指向插入位置**之后**的元素的迭代器、指针和引用将会失效
  * 对于 deque ：插入到**除首尾位置之外**的任何位置都会导致迭代器、指针和引用失效；如果在首尾位置添加元素，迭代器会失效，但指向存在的元素的引用和指针不会失效
  * 对于 list 和 forward_list ：指向容器的迭代器（包括尾后迭代器和首前迭代器）、指针和引用仍有效
* 从容器中删除元素
  * 对于 vector 和 string ：指向被删除元素**之前**元素的迭代器、引用和指针仍有效
  * 对于 deque ：在**首尾之外**的任何位置删除元素，指向被删除元素外其他元素的迭代器、引用和指针也会失效；如果删除首尾元素，则尾后迭代器会失效，但其他迭代器、引用和指针不受影响
  * 对于 list 和 forward_list ：指向容器的迭代器（包括尾后迭代器和首前迭代器）、指针和引用仍有效

*删除元素时，尾后迭代器总是会失效。所以不要使用变量保存 end 返回的迭代器。*

*注：向容器中添加或删除元素之后，都应该正确地重新定位迭代器。*

## 练习

* [练习 9.18](../src/quiz_9.18.cpp)
* [练习 9.19](../src/quiz_9.19.cpp)
* [练习 9.20](../src/quiz_9.20.cpp)
* [练习 9.21](../src/quiz_9.21.md)
* [练习 9.22](../src/quiz_9.22.md)
* [练习 9.23](../src/quiz_9.23.md)
* [练习 9.24](../src/quiz_9.24.cpp)
* [练习 9.25](../src/quiz_9.25.md)
* [练习 9.26](../src/quiz_9.26.cpp)
* [练习 9.27](../src/quiz_9.27.cpp)
* [练习 9.28](../src/quiz_9.28.cpp)
* [练习 9.29](../src/quiz_9.29.md)
* [练习 9.30](../src/quiz_9.30.md)
* [练习 9.31](../src/quiz_9.31.cpp)
* [练习 9.32](../src/quiz_9.32.md)
* [练习 9.33](../src/quiz_9.33.cpp)
* [练习 9.34](../src/quiz_9.34.cpp)
