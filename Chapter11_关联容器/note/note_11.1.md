# 11.1 使用关联容器

> 本章术语：
>  
> * 关联容器（associative-container）

关联容器类型：

* 按关键字有序保存元素（**红黑树**）
  * `map` ：关联数组，保存关键字-值对
  * `set` ：只保存关键字的容器
  * `multimap` ：关键字可重复出现的 map
  * `multiset` ：关键字可重复出现的 set
* 无序集合（**哈希表**）
  * `unordered_map` ：用哈希函数组织的 map
  * `unordered_set` ：用哈希函数组织的 set
  * `unordered_multimap` ：用哈希组织的、关键字可重复出现的 map
  * `unordered_multiset` ：用哈希组织的、关键字可重复出现的 set

8 个容器的不同体现在 3 个维度上：

1. set 或 map
2. 是否允许关键字重复
3. 保存元素是否有序

map 和 multimap 定义在 `<map>` 中  
set 和 multiset 定义在 `<set>` 中  
无序容器定义在 `<unordered_map>` 和 `<unordered_set>` 中

map 的使用示例：

```cpp
// 统计单词的出现次数
map<string, size_t> word_count; // 键为 string 类型，值为 size_t 类型
string word;
while (cin >> word)
    ++word_count[word]; // 使用 string 作为下标访问对应的值，如果下标不存在，会创建一个新元素并进行初始化（此处为 0 ）

for (const auto &w : word_count)
    cout << w.first << " occurs " << w.second
         << ((w.second > 1) ? " times" : " time") << endl;
// 对 map 进行范围 for 遍历，返回的元素类型是 pair
// 其中 pair.first 保存关键字，pair.second 保存值
```

set 的使用示例：

```cpp
// 统计单词的出现次数，排除 the 、and 、or 等虚词
map<string, size_t> word_count;
set<string> exclude = {"The", "But", "And", "Or", "An", "A",
                       "the", "but", "and", "or", "an", "a"};
string word;
while (cin >> word)
    if (exclude.find(word) == exclude.end()) // 在 exclude 集合中未找到 word 关键字
    // find 返回一个迭代器，如果所找关键字在 set 中，迭代器指向该关键字，否则返回尾后迭代器
        ++word_count[word];
```

## 练习

* [练习 11.1](../src/quiz_11.1.md)
* [练习 11.2](../src/quiz_11.2.md)
* [练习 11.3](../src/quiz_11.3.cpp)
* [练习 11.4](../src/quiz_11.4.cpp)
