编写一条表达式将 Query_base 指针动态转换为 AndQuery 指针。
分别使用 AndQuery 的对象以及其他类型的对象测试转换是否有效。
打印一条表示类型转换是否成功的信息，确保实际输出的结果与期望的一致。

> 答：AndQuery 使用私有构造函数，无法为本题编写可编译的代码。

```cpp
AndQuery aq(Query("hair"), Query("Alice"));
Query_base *pqb = &aq;

if (AndQuery *paq = dynamic_cast<AndQuery *>(pqb))
{
    if (typeid(*paq) == typeid(AndQuery))
    {
        cout << "success" << endl;
    }
}
else
{
    cout << "fail" << endl;
}
```
