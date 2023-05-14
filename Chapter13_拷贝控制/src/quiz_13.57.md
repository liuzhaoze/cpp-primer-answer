如果 sorted 定义如下，会发生什么：

```cpp
Foo Foo::sorted() const &
{
    return Foo(*this).sorted();
}
```

> 答：`Foo(*this)` 会使用本对象的数据创建一个临时对象。该临时对象是右值，对其调用 sorted 实际上会调用 `Foo Foo::sorted() &&` ，因此不会发生无限递归调用。
