# 11.2 关联容器概述

> 本章术语：
>
> * 严格弱序（strict weak ordering）：小于等于

无论是有序关联容器还是无序关联容器，都**支持** [9.2 节](../../Chapter9_%E9%A1%BA%E5%BA%8F%E5%AE%B9%E5%99%A8/note/note_9.2.md) 中的普通容器操作。  
关联容器**不支持**顺序容器位置相关的操作，如 push_front 和 push_back 。  
关联容器也**不支持**接受一个元素和一个数量的构造函数和插入操作。

## 11.2.1 定义关联容器

关联容器的初始化：

```cpp
// 初始化空容器
map<string, size_t> word_count;

// 列表初始化
set<string> article = {"a", "an", "the"};
map<string, string> authors = { {"Joyce", "James"},
                                {"Austen", "Jane"},
                                {"Dickens", "Charles"} }; // {key, value}

// 使用迭代器范围初始化
vector<int> ivec = {0, 0, 1, 1, 2, 2, 3, 3, 4, 4,
                    5, 5, 6, 6, 7, 7, 8, 8, 9, 9};
set<int> iset(ivec.cbegin(), ivec.cend()); // 含有 10 个元素
multiset<int> miset(ivec.cbegin(), ivec.cend()); // 含有 20 个元素
```

## 11.2.2 关键字类型的要求

对于有序容器——map 、multimap 、set 和 multiset ，关键字类型必须定义元素的比较方法。默认使用 `<` 运算符。

无序容器关键字的要求见 [11.4 节](./note_11.4.md)。

有序容器关键字应当满足严格弱序：

* 两个关键字不能同时“小于等于”对方：如果 k1 “小于等于” k2 ，那么 k2 绝不能“小于等于” k1
* 如果 k1 “小于等于” k2 ，且 k2 “小于等于” k3 ，那么 k1 必须“小于等于” k3
* 如果存在两个关键字，任何一个都不“小于等于”另一个，那么我们称这两个关键字是“等价”的。如果 k1 “等价于” k2 ，且 k2 “等价于” k3 ，那么 k1 必须“等价于” k3

在创建 multiset 时使用自定义的比较函数：

```cpp
multiset<Sales_data, decltype(compareIsbn)*> bookstore(compareIsbn);
// multiset 的第一个类型是关键字的类型，第二个类型是函数指针类型
// 定义的对象使用 () 指明自定义的比较函数
```

decltype 在此处的用法见 [6.7 节](../../Chapter6_%E5%87%BD%E6%95%B0/note/note_6.7.md)。

## 11.2.3 pair 类型

pair 定义在 `<utility>` 中。

pair 的默认构造函数对数据成员进行值初始化。

pair 上的操作：

* `pair<T1, T2> p;` ：定义 pair 类型的变量 p ，其两个类型的成员都进行了值初始化
* `pair<T1, T2> p(v1, v2);` ：使用 v1 和 v2 对 p 进行初始化
* `pair<T1, T2> p{v1, v2};` ：使用 v1 和 v2 对 p 进行初始化
* `pair<T1, T2> p = {v1, v2};` ：使用 v1 和 v2 对 p 进行初始化
* `make_pair(v1, v2)` ：返回一个用 v1 和 v2 初始化的 pair ，pair 的类型从 v1 和 v2 的类型推断出来
* `p.first` ：返回 p 的第一个数据成员，是 public 的
* `p.second` ：返回 p 的第二个数据成员，是 public 的
* `p1 relop p2` ：使用关系运算符（< 、<= 、> 、>=）比较两个数据成员；如果 p1.first < p2.first ，那么 p1 < p2 返回 true 。如果 p1.first == p2.first ，那么如果 p1.second < p2.second ，那么 p1 < p2 返回 true ，否则 p1 < p2 返回 false 。
* `p1 == p2` 、`p1 != p2` ：当两个成员分别相等时，两个 pair 相等，否则不相等

将 pair 作为函数的返回值：

```cpp
pair<string, int> process(vector<string> &v)
{
    if (!v.empty())
        return {v.back(), v.back().size()}; // 使用大括号列表构造 pair
        或者
        return make_pair(v.back(), v.back().size()); // 使用 make_pair 构造 pair
        或者
        return pair<string, int>(v.back(), v.back().size()); // 显式构造返回值
    else
        return pair<string, int>(); // 隐式构造返回值
}
```

## 练习

* [练习 11.5](../src/quiz_11.5.md)
* [练习 11.6](../src/quiz_11.6.md)
* [练习 11.7](../src/quiz_11.7.cpp)
* [练习 11.8](../src/quiz_11.8.cpp)
* [练习 11.9](../src/quiz_11.9.cpp)
* [练习 11.10](../src/quiz_11.10.md)
* [练习 11.11](../src/quiz_11.11.cpp)
* [练习 11.12](../src/quiz_11.12.cpp)
* [练习 11.13](../src/quiz_11.13.cpp)
* [练习 11.14](../src/quiz_11.14.cpp)
