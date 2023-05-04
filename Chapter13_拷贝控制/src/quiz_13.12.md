在下面的代码片段中会发生几次析构函数调用？

```cpp
bool fcn(const Sales_data *trans, Sales_data accum)
{
    Sales_data item1(*trans), item2(accum);
    return item1.isbn() != item2.isbn();
}
```

> 答：总共 3 次：
>
> 1. `item1` 调用一次
> 2. `item2` 调用一次
> 3. `accum` 调用一次
