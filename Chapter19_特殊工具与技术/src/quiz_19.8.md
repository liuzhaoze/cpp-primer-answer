编写一条 typeid 表达式检查两个 Query_base 对象是否指向同一种类型。
再检查该类型是否是 AndQuery 。

> 答：

```cpp
Query_base *pqb1 = ...;
Query_base *pqb2 = ...;

if (typeid(*pqb1) == typeid(*pqb2))
{
    if (typeid(*pqb1) == typeid(AndQuery))
    {
        // ...
    }
}
```
