下面的声明合法吗？如果不合法，请解释原因；如果合法，请指出该声明的含义。

```cpp
BinaryQuery a = Query("fiery") & Query("bird");
AndQuery b = Query("fiery") & Query("bird");
OrQuery c = Query("fiery") & Query("bird");
```

> 答：三条语句都不合法。`BinaryQuery` 含有纯虚函数 `eval` ，是抽象基类，无法创建对象。
> `&` 运算符返回 `Query` 对象，其不在 `Query_base` 的继承体系内，无法进行类型转换。
