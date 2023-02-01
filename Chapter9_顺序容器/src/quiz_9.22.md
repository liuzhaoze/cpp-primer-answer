假定 iv 是一个 int 的 vector，下面的程序存在什么错误？
你将如何修改？

```cpp
vector<int>::iterator iter = iv.begin(),
                      mid = iv.begin() + iv.size() / 2;

while (iter != mid)
    if (*iter == some_val)
        iv.insert(iter, 2 * some_val);
```

> 答：该程序是死循环，iter 不会等于 mid ，while 循环永远不会结束。`mid` 迭代器在插入元素后会失效。

```cpp
vector<int>::iterator iter = iv.begin(),
                      mid = iv.begin() + iv.size() / 2;

while (iter != mid)
{
    if (*iter == some_val)
        iv.insert(iter, 2 * some_val);
    
    iter += 2;
    mid = iv.begin() + iv.size() / 2;
}
```
