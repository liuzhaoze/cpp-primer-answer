# 14.5 下标运算符

下标运算符必须是成员函数。

下标运算符通常定义两个版本：一个返回普通引用，另一个返回常量引用，并且是类的常量成员。

例：

```cpp
std::string &StrVec::operator[](std::size_t n)
{
    return element[n];
}

const std::string &StrVec::operator[](std::size_t n) const
{
    return element[n];
}
```

## 练习

* [练习 14.26](../src/quiz_14.26.md)
