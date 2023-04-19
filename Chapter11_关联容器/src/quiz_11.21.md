假定 word_count 是一个 string 到 size_t 的 map ，word 是一个 string ，解释下面循环的作用：

```cpp
while (cin >> word)
    ++word_count.insert({word, 0}).first->second;
```

> 答：向 word_count 中添加关键字为 word 值为 0 的元素。  
> 如果关键字不存在，会添加该关键字，且值为 0 ，并对值进行自增操作；  
> 如果关键字存在，则直接找到对应关键字，对值进行自增操作。
