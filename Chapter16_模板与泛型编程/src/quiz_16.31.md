如果我们将 DebugDelete 与 unique_ptr 一起使用，解释编译器将删除器处理为内联形式的可能方式。

> 答：在 DebugDelete 中，对指针调用删除操作的代码如下：

```cpp
template <typename T> void operator()(T *p) const
{
    os << "deleting unique_ptr" << std::endl;
    delete p;
}
```

> 如果将 DebugDelete 设置为 unique_ptr 的删除器：`unique_ptr<int, DebugDelete>` ，那么内联形式可能是下面这种：

```cpp
~unique_ptr()
{
    std::cerr << "deleting unique_ptr" << std::endl;
    delete p;
}
```

> 将 DebugDelete 中的代码的等价形式直接写入 unique_ptr 的析构函数中。
