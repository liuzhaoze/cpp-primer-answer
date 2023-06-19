使用[上一个练习](./quiz_19.3.md)定义的类改写下面的代码，将表达式 `*pa` 转换成类型 `C&` ：

```cpp
if (C *pc = dynamic_cast<C *>(pa))
{
    // 使用 C 的成员
}
else
{
    // 使用 A 的成员
}
```

> 答：

```cpp
try
{
    C &rc = dynamic_cast<C &>(ra);
    // 使用 C 的成员
}
catch (bad_cast)
{
    // 使用 A 的成员
}
```
