如果 sorted 定义如下，会发生什么：

```cpp
Foo Foo::sorted() const &
{
    Foo ret(*this);
    return ret.sorted();
}
```

> 答：在函数中 ret 是一个左值，因此 `ret.sorted()` 会调用 `Foo Foo::sorted() const &` 而非 `Foo Foo::sorted() &&` 。  
> 因此函数会无限递归调用其自身，直到发生栈溢出。
