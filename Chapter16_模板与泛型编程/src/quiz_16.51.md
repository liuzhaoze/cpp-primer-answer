调用本节中的每个 foo ，确定 `sizeof...(Args)` 和 `sizeof...(rest)` 分别返回什么。

```cpp
template <typename T, typename... Args>
void foo(const T &t, const Args& ... rest);

int i = 0;
double d = 3.14;
string s = "how now brown cow";

foo(i, s, 42, d); // (a)
foo(s, 42, "hi"); // (b)
foo(d, s);        // (c)
foo("hi");        // (d)
```

> 答：  
> (a) `sizeof...(Args)` 返回 3 ； `sizeof...(rest)` 返回 3  
> (b) `sizeof...(Args)` 返回 2 ； `sizeof...(rest)` 返回 2  
> (c) `sizeof...(Args)` 返回 1 ； `sizeof...(rest)` 返回 1  
> (d) `sizeof...(Args)` 返回 0 ； `sizeof...(rest)` 返回 0
