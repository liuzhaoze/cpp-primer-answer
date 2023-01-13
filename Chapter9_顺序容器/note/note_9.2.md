# 9.2 容器库概览

所有容器都支持的操作：

* 类型别名
  * `iterator` ：容器的迭代器
  * `const_iterator` ：可以读取元素，但不能修改元素的迭代器
  * `size_type` ：无符号整型，可以表示该容器可容纳元素个数的最大值
  * `difference_type` ：带符号整型，可以表示两个迭代器距离的最大值
  * `value_type` ：元素类型
  * `reference` ：元素的左值类型，与 `value_type &` 含义相同
  * `const_reference` ：元素的 const 左值类型，即 `const value_type &`
* 构造函数
  * `C c;` 默认构造函数，构造空容器
  * `C c1(c2);` 构造 c1 ，内容是 c2 的拷贝
  * `C c(b, e);` 构造 c ，内容是迭代器 b 和 e 范围内的元素（ array 不支持）
  * `C c{a, b, c ...};` 列表初始化 c
* 赋值与 swap
  * `c1 = c2` 将 c1 中的元素替换为 c2 中的元素
  * `c1 = {a, b, c ...}` 将 c1 中的元素替换为列表中的元素（ array 不支持）
  * `a.swap(b)` 交换 a 和 b 的元素
  * `swap(a, b)` 与 `a.swap(b)` 等价
* 大小
  * `c.size()` c 中元素的数目（ forward_list 不支持）
  * `c.max_size()` c 可保存的最大元素数目
  * `c.empty()` 如果 c 为空容器，返回 true ，否则返回 false
* 添加/删除元素（ array 不支持）
  * `c.insert(args)` 将 args 中的元素拷贝进 c
  * `c.emplace(inits)` 使用 inits 构造 c 中的一个元素
  * `c.erase(args)` 删除 args 指定的元素
  * `c.clear()` 删除 c 中的所有元素，返回 void
  * 注：上述操作在不同的容器中，接口名都不同
* 关系运算符
  * `==` 、 `!=` 所有容器都支持相等/不等运算符
  * `<` 、 `<=` 、 `>` 、 `>=` 无序关联容器不支持
* 获取迭代器
  * `c.begin()` 、 `c.end()` 返回指向 c 的首元素/尾后元素的迭代器
  * `c.cbegin()` 、 `c.cend()` 返回 const_iterator
* 反向容器的额外成员（不支持 forward_list）
  * `reverse_iterator` 按逆序寻址元素的迭代器
  * `const_reverse_iterator` 不能修改元素的逆序迭代器
  * `c.rbegin()` 、 `c.rend()` 返回指向 c 的尾元素/首前元素的迭代器
  * `c.crbegin()` 、 `c.crend()` 返回 const_reverse_iterator

## 9.2.1 迭代器

迭代器范围：begin 指向第一个元素，end 指向最后一个元素之后的位置。

迭代器 begin 和 end 构成一个迭代器范围，应当满足的条件：

1. 他们指向同一个容器中的元素或尾后元素
2. begin 要在 end 之前

迭代器范围具有的性质：

1. 如果 begin 等于 end ，则范围为空
2. 如果 begin 不等于 end ，则范围至少包含一个元素，且 begin 指向该范围中的第一个元素
3. 可以对 begin 递增若干次，使得 begin 等于 end

## 9.2.2 容器类型成员

对一个反向迭代器执行 ++ 操作，会得到上一个元素：

```cpp
vector<class T>::reverse_iterator rit = c.rbegin(); // rit 指向倒数第一个元素
++rit; // rit 指向倒数第二个元素
```

返回容器中元素的类型：

```cpp
vector<class T>::value_type i; // i 的类型就是 T
```

返回容器中元素的引用类型：

```cpp
vector<class T>::reference r = *vec.begin(); // 将 vec 的第一个元素绑定到引用 r 上
vector<class T>::const_reference cr = *vec.begin(); // 绑定常量引用
```

## 9.2.3 begin 和 end 成员

带 r 的版本返回反向迭代器；以 c 开头的版本返回 const 迭代器。

```cpp
list<string> a = {"Apple", "Banana", "Cherry"};
auto it1 = a.begin(); // list<string>::iterator
auto it2 = a.rbegin(); // list<string>::reverse_iterator
auto it3 = a.cbegin(); // list<string>::const_iterator
auto it4 = a.crbegin(); // list<string>::const_reverse_iterator
// 显式指定类型（普通可以转化为 const ；const 不能转化为普通）
list<string>::iterator it5 = a.begin();
list<string>::const_iterator it6 = a.begin();

auto it7 = a.begin(); // 仅当 a 是 const 时，it7 是 const_iterator
```

*当不需要写访问时，应使用 cbegin 和 cend 。*

## 9.2.4 容器定义和初始化

容器定义和初始化方式：

* `C c;` ：默认构造函数。如果 C 是一个 array ，则 c 中元素按默认方式初始化；否则 c 为空
* `C c1(c2);` ：c1 初始化为 c2 的拷贝，两者必须类型相同
* `C c1 = c2;` ：同上
* `C c{a, b, c ...};` ：c 初始化为初始化列表中元素的拷贝
* `C c = {a, b, c ...};` ：同上
* `C c(b, e);` ：c 初始化为迭代器 b 和 e 指定范围中的元素的拷贝
* `C seq(n);` ：seq 包含 n 个元素，这些元素进行了值初始化（该构造函数是 explicit 的）
* `C seq(n, t);` ：seq 包含 n 个初始化为 t 的元素

只有顺序容器的构造函数接受大小参数 n ，关联容器不支持。

`C c1(c2);` 和 `C c1 = c2;` 要求容器类型和元素类型必须相同；  
`C c(b, e);` 迭代器所指容器类型可以和 c 不同，两者元素类型可以不同，能够完成类型转换即可。

```cpp
list<string> authors = {"Jack", "Tom", "Jerry"};
vector<const char *> articles = {"a", "an", "the"};

deque<string> auth_list = authors; // 错误：容器类型不匹配
vector<string> words = articles; // 错误：元素类型不匹配

forward_list<string> words(articles.begin(), articles.end());
// 正确：容器类型可以不同，const char * 可以转化为 string
```

array 容器类型包含**元素类型和大小**：

```cpp
array<int, 42> iarr;
array<string, 10> sarr;

// 使用 array 类型时，必须同时指定元素类型和大小
array<int, 10>::size_type i;
array<int>::size_type j; // 错误：未指定容器大小
```

array 的初始化方式：

```cpp
array<int, 5> ia1; // 执行默认初始化
array<int, 5> ia2 = {0, 1, 2, 3, 4}; // 执行列表初始化
array<int, 5> ia3 = {42}; // ia3[0]为42，其余元素执行值初始化（初始化为0）
```

*如果元素类型是类类型，则该类必须有一个默认构造函数，以便进行值初始化。*

不能对内置数组类型进行拷贝或赋值，但是可以对 array 类型进行拷贝或赋值。

## 9.2.5 赋值和 swap

* 赋值
  * `c1 = c2` ：将 c1 中的所有元素替换为 c2 中元素的拷贝，两者必须具有相同的类型
  * `c = {a, b, c ...}` ：将 c 中的所有元素替换为初始化列表中元素的拷贝（array不能进行花括号列表赋值）

* 顺序容器的 assign 方法（assign**不要求**容器类型相同，元素类型可以相互转化即可）
  * `seq.assign(b, e)` ：将 seq 中的所有元素替换为迭代器 b 和 e 所表示的范围中的元素，迭代器不能指向 seq 本身的元素
  * `seq.assign({a, b, c...})` ：将 seq 中的所有元素替换为初始化列表中的元素（要求列表元素类型与容器元素类型相同）
  * `seq.assign(n, t)` ：将 seq 中的所有元素替换为 n 个值为 t 的元素

* swap 方法
  * `swap(c1, c2)` ：交换 c1 和 c2 中的元素，两者必须具有相同的类型
  * `c1.swap(c2)` ：同上

*推荐统一使用非成员版本的 swap ：`swap(c1, c2)` 。*

赋值运算会导致指向左边容器内部的迭代器、引用和指针失效。

除 string 以外，指向容器的迭代器、引用和指针在 swap 之后都**不会**失效，并且仍然指向原来的元素。

```cpp
vector<int> ivec1 = {0, 0, 0};
vector<int> ivec2 = {1, 1, 1};
vector<int>::iterator iter = ivec1.begin(); // iter 指向 ivec1[0]

swap(ivec1, ivec2); // iter 指向 ivec2[0] （依旧是交换之前的那个元素）
```

与其他容器不同，swap 两个 array 会真正交换他们的元素。迭代器、引用和指针指向的元素不变，但是元素的内容发生了交换。

```cpp
array<int, 3> iarr1 = {0, 0, 0};
array<int, 3> iarr2 = {1, 1, 1};
array<int, 3>::iterator iter = iarr1.begin(); // iter 指向 iarr1[0] = 0

swap(iarr1, iarr2); // iter 依旧指向 iarr1[0] = 1
```

*总结：迭代器、引用和指针所指向的地址，在 swap 操作前后不发生改变。array 交换的是元素内容，其他容器交换的是容器名。*

## 9.2.6 容器大小操作

每个容器都有三个与大小相关的操作：

* `c.size()` ：返回容器中元素的数目
* `c.empty()` ：容器为空时返回 true ，否则返回 false
* `c.max_size()` ：返回该类型容器所能容纳的最大元素数

forward_list 不支持 size ，支持 empty 和 max_size 。

## 9.2.7 关系运算符

所有容器类型都支持相等运算符：`==` 和 `!=`  
除了无序关联容器以外的所有容器都支持关系运算符：`>` 、 `>=` 、 `<` 、 `<=` 。  
关系运算符左右两边的容器类型必须相同，元素类型也必须相同。

运算符工作方式：

* 如果两个容器大小相同且所有元素两两对应相等，则两个容器相等；否则两个容器不等
* 如果两个容器大小不同，但是小容器中的每个元素都等于大容器中的对应元素，则小容器小于大容器
* 如果两个容器都不是另一个容器的前缀子序列，则他们的比较结果取决于第一个不相等的元素的比较结果

容器的相等运算符使用元素的相等运算符 `==` 实现比较；容器的其他运算符都使用元素的 `<` 运算符实现比较。  
所以，如果两个容器可以使用关系运算符进行比较，则容器中的元素必须支持相等运算符或小于运算符的比较。

## 练习

* [练习 9.2](../src/quiz_9.2.cpp)
* [练习 9.3](../src/quiz_9.3.md)
* [练习 9.4](../src/quiz_9.4.cpp)
* [练习 9.5](../src/quiz_9.5.cpp)
* [练习 9.6](../src/quiz_9.6.md)
* [练习 9.7](../src/quiz_9.7.md)
* [练习 9.8](../src/quiz_9.8.md)
* [练习 9.9](../src/quiz_9.9.md)
* [练习 9.10](../src/quiz_9.10.md)
* [练习 9.11](../src/quiz_9.11.md)
* [练习 9.12](../src/quiz_9.12.md)
* [练习 9.13](../src/quiz_9.13.cpp)
* [练习 9.14](../src/quiz_9.14.cpp)
* [练习 9.15](../src/quiz_9.15.cpp)
* [练习 9.16](../src/quiz_9.16.cpp)
* [练习 9.17](../src/quiz_9.17.md)
