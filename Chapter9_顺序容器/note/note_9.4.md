# 9.4 vector 对象是如何增长的

vector 和 string 的内存分配策略：  
如果没有空间容纳新元素，容器会分配比新的空间需求更大的内存空间。
容器预留这些空间作为备用，可用来保存更多的新元素。
之后将已有元素从旧位置移动到新空间中，然后添加新元素，释放旧储存空间。

容器大小管理操作：

* `c.capacity()` ：在不重新分配内存空间的条件下，c 可以保存多少元素
* `c.shrink_to_fit()` ：将 capacity() 减少为与 size() 相同的大小
* `c.reserve(n)` ：分配给 c 至少能容纳 n 个元素的内存空间（空间可能比 n 更大）

`capacity` 和 `reserve` 只适用于 vector 和 string  
`shrink_to_fit` 只适用于 vector 、string 和 deque

`c.reserve(n)` 在 n 小于或等于容器当前内存空间时什么也不做。调用 reserve 永远不会减少容器占用的内存空间。  
resize 只能改变容器内的元素数量，不会改变容器占用的内存空间。

## 练习

* [练习 9.35](../src/quiz_9.35.md)
* [练习 9.36](../src/quiz_9.36.md)
* [练习 9.37](../src/quiz_9.37.md)
* [练习 9.38](../src/quiz_9.38.cpp)
* [练习 9.39](../src/quiz_9.39.cpp)
* [练习 9.40](../src/quiz_9.40.md)
