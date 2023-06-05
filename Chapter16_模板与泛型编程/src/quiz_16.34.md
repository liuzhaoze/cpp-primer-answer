对下面的代码解释每个调用是否合法。如果合法，T 的类型是什么？如果不合法，为什么？

```cpp
template <typename T> int compare(const T &, const T &);

compare("hi", "world"); // (a)
compare("bye", "dad");  // (b)
```

> 答：该函数模板的形参是两个类型相同的引用  
> (a) 不合法，两个字符数组的长度不同，实参类型不同（`char[3]` 和 `char[6]`），无法实例化  
> (b) 合法，两个字符数组长度相同，实参类型相同，可以实例化，形参类型推断为 `const char &[4]`
