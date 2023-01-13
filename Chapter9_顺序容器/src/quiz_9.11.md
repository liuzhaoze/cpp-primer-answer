对 6 种创建和初始化 vector 对象的方法，每一种都给出一个实例。
解释每个 vector 包含什么值。

> 答：

```cpp
vector<int> vec; // 空 vector
vector<int> vec(10); // 10 个元素值为 0 的 vector
vector<int> vec(10, 1); // 10 个元素值为 1 的 vector
vector<int> vec{1, 2, 3, 4, 5}; // 元素值分别为 1, 2, 3, 4, 5 的 vector
vector<int> vec(other_vec); // 与 other_vec 中的元素相同
vector<int> vec(other_vec.begin(), other_vec.end()); // 与 other_vec 中的元素相同
```
