回忆我们在 8.1 节进行的讨论，解释下面代码中将 ifstream 传递给 Sales_data 的 read 函数的程序是如何工作的。

```cpp
std::istream &read(std::istream &, Sales_data &);
```

> 答：`ifstream` 类是基类 `istream` 的派生类，在 ifstream 传递给 read 函数时发生了动态绑定。
