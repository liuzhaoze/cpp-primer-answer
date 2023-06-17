已知有下面的 swap 的经典定义，当 mem1 是一个 string 时程序使用 swap 的哪个版本？
如果 mem1 是 int 呢？说明在这两种情况下名字查找的过程。

```cpp
void swap(T v1, T v2)
{
    using std::swap;
    swap(v1.mem1, v2.mem1);
    // 交换类型 T 的其他成员
}
```

> 答：  
> 当 mem1 是 string 时，程序将使用具有 string 参数的标准库函数  
> 当 mem1 是 int 时，程序将使用带有 int 参数的标准库模板版本
