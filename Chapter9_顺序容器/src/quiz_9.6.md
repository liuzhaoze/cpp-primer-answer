下面程序有何错误？你应该如何修改他？

```cpp
list<int> lst1;
list<int>::iterator iter1 = lst1.begin(),
                    iter2 = lst1.end();

while (iter1 < iter2) /* ... */
```

> 答：`iter1 < iter2` 应改为 `iter1 != iter2`。  
> 因为 list 是双向链表，其节点的地址不连续，不能通过地址大小判断节点的先后位置。
