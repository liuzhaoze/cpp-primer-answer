重写 12.3 节中的 TextQuery 程序，使用 tuple 代替 QueryResult 类。
你认为哪种设计更好？为什么？

> 答：TextQuery 中的 query 方法此时返回一个 `tuple<string, shared_ptr<set<TextQuery::line_no>>, StrBlob>` 代替 QueryResult 的成员。
>
> 我认为使用 QueryResult 类的设计更好。因为使用类可以定义很多成员函数，可以更灵活地处理返回结果。
