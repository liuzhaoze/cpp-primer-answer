给定下面的类，解释每个 print 函数的机理：

```cpp
class base
{
private:
    string basename;

public:
    string name() { return basename; }
    virtual void print(ostream &os) { os << basename; }
};

class derived : public base
{
private:
    int i;

public:
    void print(ostream &os) { print(os); os << " " << i; }
};
```

在上述代码中存在问题吗？如果有，你该如何修改它？

> 答：base 类中的 print 将成员 basename 输出到输出流 os 上；derived 类中的 print 首先输出该类继承来的 basename 成员，然后输出自己的成员 i 。
>
> 上述代码存在问题：
>
> 1. 应该在覆盖虚函数的声明中添加 override
> 2. 函数体中的 print 调用会发生递归定义，应该使用作用域运算符指定要调用的函数
>
> 应该为：`void print(ostream &os) override { base::print(os); os << " " << i; }`
