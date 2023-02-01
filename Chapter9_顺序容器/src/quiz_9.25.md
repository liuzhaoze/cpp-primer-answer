对于下面删除一个范围内的元素的程序，如果 elem1 与 elem2 相等会发生什么？
如果 elem2 是尾后迭代器，或者 elem1 和 elem2 都是尾后迭代器，又会发生什么？

`elem1 = slist.erase(elem1, elem2);`

> 答：当 elem1 等于 elem2 时，迭代器范围为空，什么也不会发生。  
> 当 elem2 是尾后迭代器时，会删除包括 elem1 及其后面的所有元素。
