# 17.1 tuple 类型

tuple 类似于 pair 。只不过 pair 只能组合两个对象，而 tuple 可以组合不限数量的对象。

tuple 支持的操作：

* `tuple<T1, T2, ..., Tn> t;` ：t 是一个 tuple ，有 n 个成员，第 i 个成员的类型为 Ti 。所有成员都进行值初始化。
* `tuple<T1, T2, ..., Tn> t(v1, v2, ..., vn);` ：t 是一个 tuple ，每个成员使用对应的初始值 vi 进行初始化。此构造函数是 explicit 的。
* `make_tuple(v1, v2, ..., vn)` ：返回一个用给定初始值初始化的 tuple ，tuple 的类型从初始值的类型推断
* `t1 == t2` ：当两个 tuple 的成员数量相同，对应成员也相等时，两个 tuple 相等
* `t1 != t2` ：两个 tuple 数量不同，或者存在一对对应成员不等
* `t1 relop t2` ：relop 是关系运算符，两个 tuple **必须**具有相同数量的成员，使用 `<` 运算符比较对应的成员
* `get<i>(t)` ：返回 tuple t 的第 i 个数据成员的引用；如果 t 是左值，就返回左值引用，如果 t 是右值，就返回右值引用
* `tuple_size<tupleType>::value` ：类模板 tuple_size 使用一个 tuple 类型初始化，该类模板有一个 public constexpr static size_t 数据成员 value ，表示给定 tuple 类型中成员的数量
* `tuple_element<i, tupleType>::type` ：类模板 tuple_element 使用一个整型常量和一个 tuple 类型初始化，该类模板有一个 public 成员，表示给定 tuple 中第 i 个成员的类型

## 17.1.1 定义和初始化 tuple

explicit 的构造函数必须使用直接初始化语法：

```cpp
tuple<size_t, size_t, size_t> threeD = {1, 2 ,3}; // 错误
tuple<size_t, size_t, size_t> threeD{1, 2 ,3};    // 正确
```

```cpp
auto item = make_tuple("0-999-78345-X", 3, 20.00); // tuple 类型通过初始值推断

auto book  = get<0>(item); // 返回 item 的第一个成员
auto cnt   = get<1>(item); // 返回 item 的第二个成员
auto price = get<2>(item); // 返回 item 的第三个成员
```

获得 tuple 的成员数量和成员类型：

```cpp
using tuple_type = decltype(item); // 获得了 item 的类型
size_t sz = tuple_size<tuple_type>::value; // sz = 3
tuple_element<1, tuple_type>::type cnt = get<1>(item); // 获得了 item 第二个成员的类型
```

tuple 定义了 `==` 和 `<` 运算符，可以将 tuple 传递给算法，也可以将 tuple 作为无序容器中的关键字类型。  
tuple 中的成员也需要支持 `==` 和 `<` 运算符。

## 17.1.2 使用 tuple 返回多个值

tuple 的一个常见用途是从一个函数返回多个值。pair 是从一个函数返回两个值。

### 应用举例

现有 4 家书店，每家书店都有自己的书籍销售记录（[store1](../data/store1) 、[store2](../data/store2) 、[store3](../data/store3) 和 [store4](../data/store4)）。
每家书店的销售记录 `Sales_data` 都存放在一个 `vector<Sales_data>` 中。然后将这 4 家书店的销售记录全部存放在一个 `vector<vector<Sales_data>>` 中。

* 编写函数 `findBook` ，在全部销售记录中搜索卖过这本书的书店。使用 tuple 保存每家店的查询结果：在 `vector<vector<Sales_data>>` 中的索引，该本书在 `vector<Sales_data>` 中的首位置和尾后位置。
* 编写函数 `reportResults` ，输出指定查询书目的销售记录。

具体实现及说明见[练习 17.4](../src/quiz_17.4.cpp) 。

## 练习

* [练习 17.1](../src/quiz_17.1.cpp)
* [练习 17.2](../src/quiz_17.2.cpp)
* [练习 17.3](../src/quiz_17.3.md)
* [练习 17.4](../src/quiz_17.4.cpp)
* [练习 17.5](../src/quiz_17.5.cpp)
* [练习 17.6](../src/quiz_17.6.cpp)
* [练习 17.7](../src/quiz_17.7.md)
* [练习 17.8](../src/quiz_17.8.md)
