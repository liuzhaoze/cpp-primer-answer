虽然 unique_ptr 不能拷贝，但我们在 12.1.5 节中编写了一个 clone 函数，它以值方式返回一个 unique_ptr 。
解释为什么函数是合法的，以及为什么它能正确工作。

```cpp
unique_ptr<int> clone(int p)
{
    return unique_ptr<int>(new int(p));
}

unique_ptr<int> clone(int p)
{
    unique_ptr<int> ret(new int(p));

    return ret;
}
```

> 答：因为此处使用的是移动操作而非拷贝操作，所以 unique_ptr 能够保持其唯一性。因此是合法的。
