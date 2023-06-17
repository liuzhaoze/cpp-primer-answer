在下面的代码中，确定哪个函数与 compute 调用匹配。
列出所有候选函数和可行函数，对于每个可行函数的实参与形参的匹配过程来说，发生了哪种类型转换？

```cpp
namespace primerLib
{
    void compute();
    void compute(const void *);
}

using primerLib::compute;
void compute(int);
void compute(double, double = 3.14);
void compute(char *, char * = 0);

void f()
{
    compute(0);
}
```

如果将 using 声明置于 f 函数中 compute 的调用点之前将发生什么情况？重新回答之前的那些问题。

> 答：候选函数为 primerLib 命名空间和全局命名空间中总共 5 个 compute 的重载版本。除了参数列表为空的版本以外，其他 4 个版本都是可行函数。可行函数的类型转换如下：  
> `void compute(int)` 无需类型转换，最终调用该重载版本  
> `void compute(double, double = 3.14)` 将整型转换为 double  
> `void compute(char *, char * = 0)` 将整型转换为字符指针  
> `void compute(const void *)` 将整型转换为 `const void *`
>
> 当 using 声明置于 f 函数中 compute 的调用点之前时，局部作用域中的 using 声明会隐藏外层作用域中名字的声明。因此候选函数只有 primerLib 命名空间中的 2 个 compute 重载版本。可行函数只有接受一个参数的版本，参数列表为空的重载版本不可行。可行函数的类型转换如下：  
> `void compute(const void *)` 将整型转换为 `const void *`
