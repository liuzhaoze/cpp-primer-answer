下面的这个函数虽然合法，但是不算特别有用。指出他的局限性并设法改善。

```c
bool is_empty(string &s) { return s.empty(); }
```

> 答：该函数的局限性在于其不能接受字符串字面值。应该为：

```c
bool is_empty(const string &s) { return s.empty(); }
```
