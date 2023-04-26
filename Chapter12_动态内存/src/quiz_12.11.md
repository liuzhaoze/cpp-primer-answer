如果我们像下面这样调用 process ，会发生什么？

```cpp
void process(shared_ptr<int> ptr)
{
    // 使用 ptr
} // ptr 离开作用域，被销毁

shared_ptr<int> p(new int(42));
process(shared_ptr<int>(p.get()));
```

> 答：
>
> 1. p 被定义时，引用计数为 1
> 2. 然后在调用 process 时，将 p 对应的内置指针拷贝给形参 ptr 。因为**对内置指针的拷贝不会增加引用计数**，所以引用计数保持为 1
> 3. process 退出时，销毁形参 ptr ，引用计数减为 0 ，释放动态对象
> 4. 主函数退出时，销毁智能指针 p ，发现引用计数为 0 ，**重复释放动态对象**
