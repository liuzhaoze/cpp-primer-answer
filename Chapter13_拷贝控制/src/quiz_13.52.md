详细解释第 478 页中的 HasPtr 对象的赋值发生了什么？
特别是，一步一步描述 hp 、hp2 以及 HasPtr 的赋值运算符中的参数 rhs 的值发生了什么变化。

```cpp
class HasPtr
{
public:
    // 移动构造函数
    HasPtr(HasPtr &&p) noexcept : ps(p.ps), i(p.i)
    {
        p.ps = 0;
    }

    // 使用拷贝并交换技术的赋值运算符
    HasPtr &operator=(HasPtr rhs)
    {
        swap(*this, rhs);
        return *this;
    }
};

hp = hp2;
hp = std::move(hp2);
```

> 答：
>
> 在执行 `hp = hp2;` 时，hp2 是左值，因此使用拷贝构造函数初始化形参 rhs 。赋值运算符会申请一片内存，将 hp2 的内容拷贝到该内存中。赋值结束后 hp2 依旧可以访问，其行为就是拷贝赋值运算符。
>
> 在执行 `hp = std::move(hp2);` 时，std::move(hp2) 返回一个右值引用，因此使用移动构造函数让 rhs 接管 hp2 管理的内存，而不会分配任何内存。赋值结束后，hp2 不应该再被使用，其行为就是移动赋值运算符。
>
> 在 swap 交换完毕后，rhs 所管理的内存无论在哪种情况下都会被销毁。
