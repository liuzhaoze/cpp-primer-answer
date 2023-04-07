# 10.2 初识泛型算法

> 本章术语：
>  
> * 输入范围：标准库算法对一个范围内的元素进行操作
> * 插入迭代器（insert iterator）：一种向容器中添加元素的迭代器

[附录 A](../../AppendixA_%E6%A0%87%E5%87%86%E5%BA%93/A.2_%E7%AE%97%E6%B3%95%E6%A6%82%E8%A7%88.md)
按操作方式列出了所有算法。

## 10.2.1 只读算法

`find` 、`count` 、`accumulate` 、`equal` 只会读取其输入范围内的元素，而从不改变元素。

```cpp
#include <numeric>
int sum = accumulate(vec.cbegin(), vec.cend(), 0);
// 将 sum 设置为 vec 中元素的和，和的初始值被设置为 0
// 第 3 个参数的类型决定了函数中使用哪个加法运算符以及返回值的类型

string sum = accumulate(v.cbegin(), v.cend(), string("")); // 使用 + 进行拼接
string sum = accumulate(v.cbegin(), v.cend(), ""); // 错误：""是 const char * ，没有 + 运算符
```

```cpp
equal(roster1.cbegin(), roster1.cend(), roster2.cbegin());
// roster1 与 roster2 所有对应元素都相等，返回 true ，否则返回 false
// 第二个序列的长度大于等于第一个序列的长度
// roster1 可以是 vector<string>
// roster2 可以是 list<const char *>
// 只要元素能用 == 进行比较即可
```

## 10.2.2 写容器元素的算法

```cpp
fill(vec.begin(), vec.end(), 0); // 将每个元素置为 0
fill(vec.begin(), vec.begin() + vec.size() / 2, 10); // 将容器的一个子序列设置为 10
```

*算法不检查写操作。*

```cpp
vector<int> ivec; // 空 vector
fill_n(vec.begin(), vec.size(), 0); // 正确：将所有元素置为 0
fill_n(vec.begin(), 10, 0); // 错误：ivec 不存在 10 个元素的位置，算法的结果是未定义的
```

使用插入迭代器来保证算法有足够的元素空间容纳输出数据。

```cpp
vector<int> ivec; // 空 vector
auto it = back_inserter(ivec); // 接受一个指向容器的引用，返回一个与该容器绑定的插入迭代器
*it = 42; // 通过此迭代器赋值时，赋值运算符 = 会调用push_back，将一个具有给定值的元素添加到容器中，即：ivec.push_back(42)
fill_n(back_inserter(ivec), 10, 0); // 正确：向 ivec 中添加 10 个 0
```

拷贝算法（copy）：

```cpp
int a1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int a2[sizeof(a1) / sizeof(*a1)]; // a2 与 a1 大小一致

auto ret = copy(begin(a1), end(a1), a2); // 把 a1 的内容拷贝给 a2 ，ret 指向拷贝到 a2 的尾元素之后的位置
```

替换算法（replace）：

```cpp
replace(ilst.begin(), ilst.end(), 0, 42); // 将输入范围内的 0 全部替换为 42
replace(ilst.begin(), ilst.end(), back_inserter(ivec), 0, 42); // ilst 不变，将 ilst 中的 0 全部替换为 42 后的序列插入 ivec 的末尾
```

## 10.2.3 重排容器元素的算法

将一段文字中出现的单词**按字典顺序**、**不重复**地输出：

```cpp
void elimDups(vector<string> &words)
{
    sort(words.begin(), words.end()); // 将 words 按字典顺序排序
    auto end_unique = unique(words.begin(), words.end()); // 将 words 中不重复的单词放在容器前面，返回指向最后一个不重复元素之后的位置的迭代器（end_unique 及其之后的元素仍然存在，但是不知道具体的值是什么）
    words.erase(end_unique, words.end()); // 删除多余的元素
}
```

## 练习

* [练习 10.3](../src/quiz_10.3.cpp)
* [练习 10.4](../src/quiz_10.4.md)
* [练习 10.5](../src/quiz_10.5.md)
* [练习 10.6](../src/quiz_10.6.cpp)
* [练习 10.7](../src/quiz_10.7.md)
* [练习 10.8](../src/quiz_10.8.md)
* [练习 10.9](../src/quiz_10.9.cpp)
* [练习 10.10](../src/quiz_10.10.md)
