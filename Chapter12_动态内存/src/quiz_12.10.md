下面的代码调用了 process 函数，解释此调用是否正确。如果不正确，应如何修改？

```cpp
void process(shared_ptr<int> ptr)
{
    // 使用 ptr
} // ptr 离开作用域，被销毁

shared_ptr<int> p(new int(42));
process(shared_ptr<int>(p));
```

> 答：正确。
>  
> 1. p 被定义时，引用计数为 1
> 2. 然后在调用 process 时，将 p 拷贝给形参 ptr（`ptr = shared_ptr<int>(p)`），引用计数增加为 2
> 3. process 退出时，销毁形参 ptr ，引用计数减为 1
> 4. 主函数退出时，销毁智能指针 p ，引用计数减为 0 ，释放动态对象
