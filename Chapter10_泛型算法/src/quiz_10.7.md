下面程序是否有错误？如果有，请改正。

(a)

```cpp
vector<int> vec;
list<int> lst;
int i;
while (cin >> i)
    lst.push_back(i);
copy(lst.cbegin(), lst.cend(), vec.begin());
```

(b)

```cpp
vector<int> vec;
vec.reserve(10); // 见 9.4 节
fill_n(vec.begin(), 10, 0);
```

> 答：  
> (a) 错误。vec 的大小小于 lst ，应该使用插入迭代器：`copy(lst.cbegin(), lst.cend(), back_inserter(vec));` 。  
> (b) 正确，但是 vec 的大小仍为 0 。因为 reserve 仅给 vec 预留了至少 10 个元素的空间，但并没有真正分配给 vec 。应给使用 resize 将空间真正分配给 vec 。修改 `vec.resize(10);` 或 `fill_n(back_inserter(vec), 10, 0);` 。
