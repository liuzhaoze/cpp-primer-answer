假定在下面的代码中标记为“位置 1 ”的地方是对于命名空间 Exercise 中所有成员的 using 声明，请解释代码的含义。
如果这些 using 声明出现在“位置 2 ”又会怎样呢？
将 using 声明变为 using 指示，重新回答之前的问题。

```cpp
namespace Exercise
{
    int ivar = 0;
    double dvar = 0.0;
    const int limit = 1000;
}

int ivar = 0;
// 位置 1

void manip()
{
    // 位置 2
    double dvar = 3.1416;
    int iobj = limit + 1;
    ++ivar;
    ++::ivar;
}
```

> 答：
>
> 在“位置 1 ” using 声明所有 Exercise 成员，ivar 会产生二义性，dvar 和 limit 可以正常引入。在 manip 中 dvar 被同名局部变量隐藏。
>
> 在“位置 2 ” using 声明所有 Exercise 成员，dvar 会发生二次定义，ivar 和 limit 可以正常引入。Exercise 和全局作用域中的 ivar 先后自增一次。
>
> 在“位置 1 ” using 指示 Exercise 命名空间，ivar 会产生二义性，dvar 和 limit 可以正常引入。在 manip 中 dvar 被同名局部变量隐藏。
>
> 在“位置 2 ” using 指示 Exercise 命名空间，ivar 会产生二义性，dvar 和 limit 可以正常引入。在 manip 中 dvar 被同名局部变量隐藏。
