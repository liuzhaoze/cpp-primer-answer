7.5.5 节的 Data 类是字面值常量类吗？请解释原因。

```c
struct Data {
    int ival;
    string s;
};
```

> 答：不是。因为其没有 constexpr 构造函数。并且 string 不是字面值常量。
