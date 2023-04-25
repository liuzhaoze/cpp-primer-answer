# 11.3 关联容器操作

关联容器额外的类型别名：

* `key_type` ：该容器类型的关键字类型
* `mapped_type` ：每个关键字所关联的类型，只适用于 map
* `value_type` ：对于 set ，与 `key_type` 相同；对于 map ，则是 `pair<const key_type, mapped_type>`

*注意：不能改变 pair 的第一个元素的值，即：不能改变关键字。*

## 11.3.1 关联容器迭代器

map 的迭代器是指向 pair 类型的；  
set 的迭代器是指向关键字的，关键字不能修改，所以 set 的迭代器是 const 的。

可以像**顺序容器**一样使用迭代器遍历**关联容器**。  
有序容器（map 、multimap 、set 、multiset）都是按关键字升序储存元素的。

通常不对关联容器使用泛型算法。如果一定要对关联容器使用算法，它应当作为：

1. 一个源序列：使用 copy 将元素从一个关联容器中拷贝到别的地方
2. 一个目的位置：将插入器 inserter 绑定到一个关联容器上，在算法中通过 inserter 向关联容器中添加元素

## 11.3.2 添加元素

向 map 和 set 中插入一个已存在的元素对容器没有任何影响。  
对于一个给定的关键字，只有第一个带此关键字的元素才被插入到容器中。  
即：只有关键字不在容器中时，才会被插入到容器中，如果关键字已存在，即使值不同也不会插入。

* `c.insert(v)` ：v 是 value_type 类型的对象
* `c.emplace(args)` ：args 用来构造 value_type 类型的对象

上述两个函数返回一个 pair 。第一个成员是一个迭代器，指向具有指定关键字的元素；第二个成员是一个 bool 值，指示插入是否成功。  
对于 multimap 和 multiset ，总会插入给定元素，并返回指向新插入元素的迭代器，而不会返回 bool 值。

* `c.insert(b, e)` ：b 和 e 是迭代器，表示一个 c::value_type 类型值的范围
* `c.insert(il)` ：il 是花括号列表，列表中的元素是 c::value_type 类型

上述两个函数返回 void 。

* `c.insert(p, v)` ：迭代器 p 指出从哪里开始搜索新元素应该插入的位置
* `c.insert(p, args)` ：迭代器 p 指出从哪里开始搜索新元素应该插入的位置

上述两个函数返回一个迭代器，指向具有指定关键字的元素。

## 11.3.3 删除元素

* `c.erase(k)` ：从 c 中删除所有关键字为 k 的元素，返回一个 size_type 值，指出所删除的元素的数量
* `c.erase(p)` ：从 c 中删除迭代器 p 所指向的元素。p 必须指向 c 中真实存在的元素，不能等于 c.end() 。返回一个指向 p 之后元素的迭代器，如果 p 指向 c 的尾元素，则返回 c.end()
* `c.erase(b, e)` ：删除迭代器对 b 和 e 所表示的范围中的元素，返回 e

## 11.3.4 map 的下标操作

map 和 unordered_map 的下标操作：

* `c[k]` ：返回关键字为 k 的元素；如果 k 不在 c 中，添加一个关键字为 k 的元素，对其进行值初始化
* `c.at(k)` ：访问关键字为 k 的元素，带参数检查；若 k 不在 c 中，则抛出一个 out_of_range 异常（见 [9.3.2 节](../../Chapter9_%E9%A1%BA%E5%BA%8F%E5%AE%B9%E5%99%A8/note/note_9.3.md)）

不能对一个 multimap 或一个 unordered_multimap 进行下标操作，因为这些容器中可能有多个值与一个关键字相联。

只能对非 const 的 map 使用下标操作。

当对一个 map 进行下标操作时，会获得一个 mapped_type 对象；  
当解引用一个 map 迭代器时，会得到一个 value_type 对象。

map 的下标运算符返回一个左值，可读可写。

*当只想检查一个元素是否在 map 中时，应当用 at/find 方法。使用下标运算符会自动添加元素。*

## 11.3.5 访问元素

在一个关联容器中查找元素的操作：

* `c.find(k)` ：返回一个迭代器，指向第一个关键字为 k 的元素，若 k 不在容器中，则返回尾后迭代器
* `c.count(k)` ：返回关键字等于 k 的元素的数量，对不允许重复关键字的容器，返回值永远是 0 或 1
* `c.lower_bound(k)` ：返回一个迭代器，指向第一个关键字**不小于** k 的元素
* `c.upper_bound(k)` ：返回一个迭代器，指向第一个关键字**大于** k 的元素
* `c.equal_range(k)` ：返回一个迭代器 pair ，表示关键字等于 k 的元素的范围，若 k 不存在，pair 的两个成员均等于 c.end()

*注意：lower_bound 和 upper_bound 不适用于无序容器。如果给定关键字 k 不存在，两者都会返回一个指向不影响排序的关键字插入位置（即：不影响容器中元素顺序的插入位置），且两个迭代器相等。*  
*注意：下标和 at 操作只适用于非 const 的 map 和 unordered_map 。*

使用示例：

```cpp
// 检查关键字是否存在
if (word_count.find("foobar") == word_count.end())
    cout << "foobar is not in the map" << endl;

// 在允许重复关键字的容器中查找关键字
string search_item("Alain de Botton");
// 方法一：通过计数查找
auto entries = authors.count(search_item); // 关键字数量
auto iter = authors.find(search_item); // 关键字的第一个位置
while (entries) {
    cout << iter->second << endl;
    ++iter;
    --entries;
}
// 方法二：通过迭代器查找
for (auto beg = authors.lower_bound(search_item),
          end = authors.upper_bound(search_item);
     beg != end; ++beg)
    cout << beg->second << endl;
// 方法二的另一种形式
for (auto range = authors.equal_range(search_item);
     range.first != range.second; ++range.first)
    cout << range.first->second << endl;
```

## 11.3.6 一个单词转换的 map

见[练习 11.33](../src/quiz_11.33.cpp) 。

## 练习

* [练习 11.15](../src/quiz_11.15.md)
* [练习 11.16](../src/quiz_11.16.cpp)
* [练习 11.17](../src/quiz_11.17.md)
* [练习 11.18](../src/quiz_11.18.cpp)
* [练习 11.19](../src/quiz_11.19.cpp)
* [练习 11.20](../src/quiz_11.20.cpp)
* [练习 11.21](../src/quiz_11.21.md)
* [练习 11.22](../src/quiz_11.22.md)
* [练习 11.23](../src/quiz_11.23.cpp)
* [练习 11.24](../src/quiz_11.24.md)
* [练习 11.25](../src/quiz_11.25.md)
* [练习 11.26](../src/quiz_11.26.cpp)
* [练习 11.27](../src/quiz_11.27.md)
* [练习 11.28](../src/quiz_11.28.cpp)
* [练习 11.29](../src/quiz_11.29.md)
* [练习 11.30](../src/quiz_11.30.md)
* [练习 11.31](../src/quiz_11.31.cpp)
* [练习 11.32](../src/quiz_11.32.cpp)
* [练习 11.33](../src/quiz_11.33.cpp)
* [练习 11.34](../src/quiz_11.34.md)
* [练习 11.35](../src/quiz_11.35.md)
* [练习 11.36](../src/quiz_11.36.md)
