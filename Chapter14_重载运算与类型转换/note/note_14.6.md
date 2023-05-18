# 14.6 递增和递减运算符

递增和递减运算符应该定义为成员函数。

递增和递减运算符应该同时定义前置版本和后置版本。

* 前置运算符应该返回递增或递减后对象的引用
* 后置运算符应该返回递增或递减之前对象的值，而非引用

```cpp
// 前置版本：返回引用，参数列表为空
StrBlobPtr &StrBlobPtr::operator++()
{
    check(curr, "increment past end of StrBlobPtr"); // 不能递增尾后位置
    ++curr; // 前置递增成员
    return *this;
}

StrBlobPtr &StrBlobPtr::operator--()
{
    --curr; // 前置递减成员
    check(curr, "decrement past begin of StrBlobPtr"); // 不能递减 0
    return *this;
}

// 后置版本：返回值，参数列表有 int
StrBlobPtr StrBlobPtr::operator++(int)
{
    // 后置递增运算不用检查有效性
    StrBlobPtr ret = *this; // 记录递增前的值
    ++*this; // 调用前置递增检查有效性并完成递增
    return ret;
}

StrBlobPtr StrBlobPtr::operator--(int)
{
    // 后置递减运算不用检查有效性
    StrBlobPtr ret = *this; // 记录递减前的值
    --*this; // 调用前置递减检查有效性并完成递减
    return ret;
}
```

后置运算符通过调用对应的前置版本来完成实际的工作，安全性由前置版本负责检查。  
编译器会给形参 int 提供一个值为 0 的实参，但不应该使用这个形参，因此该形参没有名字。

显式调用前置和后置运算符：

```cpp
StrBlobPtr p(a1);
p.operator++();  // 调用前置版本的 operator++
p.operator++(0); // 调用后置版本的 operator++
```

## 练习

* [练习 14.27](../src/quiz_14.27.md)
* [练习 14.28](../src/quiz_14.28.md)
* [练习 14.29](../src/quiz_14.29.md)
