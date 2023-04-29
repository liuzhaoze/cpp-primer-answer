也可以这样编写 StrBlobPtr 的 deref 成员：

```cpp
std::string& deref() const
{
    return (*check(curr, "dereference past end"))[curr];
}
```

你认为哪个版本更好？为什么？

> 答：原版更好，因为原版可读性更强。
