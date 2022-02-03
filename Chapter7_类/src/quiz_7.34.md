如果我们把 Screen 类的 pos 的 typedef 放在类的最后一行会发生什么情况？

```c
int height;
class Screen
{
public:
    typedef std::string::size_type pos; // 放到最后一行
    void dummy_fcn(pos height)
    {
        cursor = width * height;
    }

private:
    pos cursor = 0;
    pos height = 0, width = 0;
}
```

> 答：会出现 `pos` 类型名没有定义的错误。
