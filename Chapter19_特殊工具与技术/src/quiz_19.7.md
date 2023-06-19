编写与[上一个练习](./quiz_19.6.md)类似的转换，这一次将 Query_base 对象转换为 AndQuery 的引用。
重复上面的测试过程，确保转换能正常工作。

> 答：AndQuery 使用私有构造函数，无法为本题编写可编译的代码。

```cpp
AndQuery aq(Query("hair"), Query("Alice"));
Query_base &rqb = aq;

try
{
    AndQuery &raq = dynamic_cast<AndQuery &>(rqb);

    if (typeid(raq) == typeid(AndQuery))
    {
        cout << "success" << endl;
    }
}
catch (bad_cast)
{
    cout << "fail" << endl;
}
```
