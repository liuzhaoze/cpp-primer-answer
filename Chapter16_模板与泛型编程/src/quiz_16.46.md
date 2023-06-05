解释下面的循环，它来自 13.5 节中的 `StrVec::reallocate` ：

```cpp
for (size_t i = 0; i != size(); ++i)
{
    alloc.construct(dest++, std::move(*elem++));
}
```

> 答：因为 construct 函数的第二个参数需要右值引用，所以使用 `std::move` 函数将左值 `*elem` 转换为右值引用。
