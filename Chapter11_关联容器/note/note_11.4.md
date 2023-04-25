# 11.4 无序容器

> 本章术语：
>
> * 无序关联容器（unordered associative container）

如果关键字类型本来就是无序的，或者通过性能测试发现可以使用哈希函数解决问题，就可以使用无序容器。

通常可以用一个无序容器替换对应的有序容器，反之亦然。无序容器也有允许重复关键字的版本。

容器将具有一个特定哈希值的所有元素都保存在相同的桶中。所有相同关键字的元素都会在同一个桶中。  
将不同关键字的元素映射到相同的桶也是允许的，桶中的元素需要顺序查找。

无序容器管理操作：

* 桶接口：
  * `c.bucket_count()` ：正在使用的桶的数目
  * `c.max_bucket_count()` ：容器能容纳的最多的桶的数量
  * `c.bucket_size(n)` ：第 n 个桶中有多少个元素
  * `c.bucket(k)` ：关键字为 k 的元素在哪个桶中
* 桶迭代：
  * `local_iterator` ：可以用来访问桶中元素的迭代器类型
  * `const_local_iterator` ：桶迭代器的 const 版本
  * `c.begin(n)` , `c.end(n)` ：桶 n 的首元素迭代器和尾后迭代器
  * `c.cbegin(n)` , `c.cend(n)` ：桶 n 的首元素迭代器和尾后迭代器，返回 const_local_iterator
* 哈希策略：
  * `c.load_factor()` ：每个桶的平均元素数量，返回 float 值
  * `c.max_load_factor()` ：c 试图维护的平均桶大小，返回 float 值。c 会在需要时添加新的桶，使得 load_factor <= max_load_factor
  * `c.rehash(n)` ：重组存储，使得 bucket_count >= n 且 bucket_count > size/max_load_factor
  * `c.reserve(n)` ：重组存储，使得 c 可以保存 n 个元素且不必 rehash

无序容器要求关键字支持 `==` 运算符和 `hash<type>` 类型对象。前者用于比较元素，后者用于计算哈希值。  
标准库中的内置类型、指针、string 、智能指针都满足上述条件，都可以作为无序容器的关键字。

自定义类类型需要定义 `==` 运算符和 `hash` 模板之后才能用于无序容器的关键字：

```cpp
size_t hasher(const Sales_data &sd)
{
    return hash<string>()(sd.isbn());
}

bool eqOp(const Sales_data &lhs, const Sales_data &rhs)
{
    return lhs.isbn() == rhs.isbn();
}

// 通过上述比较函数和哈希模板建立 Sales_data 的无序容器
using SD_multiset = unordered_multiset<Sales_data, decltype(hasher)*, decltype(eqOp)*>;
SD_multiset bookstore(42, hasher, eqOp);

// 如果类中已经定义了比较运算符 == ，则可以省略第三个参数，只定义哈希模板
unordered_set<Foo, decltype(FooHash)*> fooSet(10, FooHash);
```

## 练习

* [练习 11.37](../src/quiz_11.37.md)
* [练习 11.38(1)](../src/quiz_11.38.1.cpp)
* [练习 11.38(2)](../src/quiz_11.38.2.cpp)
