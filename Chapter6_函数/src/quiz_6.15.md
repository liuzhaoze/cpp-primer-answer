说明 `find_char` 函数中的三个形参为什么是现在的类型，  
特别说明为什么 `s` 是常量引用而 `occurs` 是普通引用？  
为什么 `s` 和 `occurs` 是引用类型而 `c` 不是？  
如果令 `s` 是普通引用会发生什么情况？  
如果令 `occurs` 是常量引用会发生什么情况？

```c
string::size_type find_char(const string &s, char c, string::size_type &occurs)
{
    auto ret = s.size();
    occurs = 0;
    for (decltype(ret) i = 0; i != s.size(); ++i)
    {
        if (s[i] == c)
        {
            if (ret == s.size())
                ret = i;
            ++occurs;
        }
    }
    return ret;
}
```

> 答：  
> s 在函数中不应该被修改，所以是常量引用； occurs 通过函数计算得到，所以是普通引用。  
> c 是临时变量，而不是别的变量的引用。  
> s 可能在函数中被修改。  
> 无法修改 occurs 的值。
