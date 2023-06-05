下面的函数是否合法？如果不合法，为什么？
如果合法，对可以传递的实参类型有什么限制（如果有的话）？返回类型是什么？

```cpp
template <typename Iter>
auto fcn(Iter beg, Iter end) -> decltype(*beg + 0)
{
    // 处理序列
    return *beg; // 返回序列中一个元素的拷贝
}
```

> 答：合法。  
> 实参类型限制：迭代器所表示的序列中的元素必须支持与 0 相加的操作。  
> 返回类型由 `operator+` 的返回类型决定。
