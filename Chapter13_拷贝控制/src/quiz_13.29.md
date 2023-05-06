解释 `swap(HasPtr &, HasPtr &)` 中对 swap 的调用不会导致递归循环。

```cpp
inline void swap(HasPtr &lhs, HasPtr &rhs)
{
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}
```

> 答：  
> 调用 `swap(lhs.ps, rhs.ps)` 实际上调用的是 `swap(string *, string *)` 实现交换指针  
> 调用 `swap(lhs.i, rhs.i)` 实际上调用的是 `swap(int, int)` 实现交换 int 型成员  
> 两者都没有递归调用 `swap(HasPtr &, HasPtr &)`  
> 因此不会导致递归循环
