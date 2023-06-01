针对[图：使用 Query 表达式创建对象](../note/note_15.9.md#使用表达式创建对象)构建的表达式：

(a) 列举出在处理表达式的过程中执行的所有构造函数。  
(b) 列举出 `cout << q` 所调用的 `rep` 。  
(c) 列举出 `q.eval()` 所调用的 `eval` 。

> 答：
>
> (a)
>
> 1. `Query::Query(const std::string& s)` 使用 "fiery" "bird" "wind" 创建三个 Query 类对象
> 2. `WordQuery::WordQuery(const std::string& s)` Query 的构造函数创建了三个 WordQuery 类对象，并指向它们
> 3. `AndQuery::AndQuery(const Query& left, const Query& right);` & 运算符使用左、右两个运算对象创建了 AndQuery 类对象
> 4. `BinaryQuery(const Query&l, const Query& r, std::string s);` AndQuery 类对象使用 BinaryQuery 的构造函数初始化子对象
> 5. `Query::Query(std::shared_ptr<Query_base> query)` BinaryQuery 的构造函数为两个运算对象分别创建对应的 Query 对象
> 6. `OrQuery::OrQuery(const Query& left, const Query& right);` | 运算符使用 AndQuery 类对象作为左运算对象和右运算对象创建了 OrQuery 类对象
> 7. `BinaryQuery(const Query&l, const Query& r, std::string s);` 同步骤 4
> 8. `Query::Query(std::shared_ptr<Query_base> query)` 同步骤 5
>
> (b)
>
> 1. 在输出运算符 << 中调用 `query.rep()`
> 2. 在 Query 类的 rep 成员函数中调用 `q->rep()`
> 3. q 的动态类型是 OrQuery ，通过动态绑定调用 `OrQuery::rep()`
> 4. `OrQuery::rep()` 继承自 BinaryQuery ，没有覆盖 rep 函数，因此调用 `BinaryQuery::rep()`
> 5. `BinaryQuery::rep()` 对左、右两个运算对象分别调用 `Query::rep()`：右侧运算对象动态类型为 `WordQuery` 实际调用 `WordQuery::rep()`；左侧运算对象动态类型为 `AndQuery` 实际调用 `AndQuery::rep()`
> 6. `AndQuery::rep()` 继承自 BinaryQuery ，没有覆盖 rep 函数，因此调用 `BinaryQuery::rep()`
> 7. `BinaryQuer::rep()` 对左、右两个运算对象分别调用 `Query::rep()`：两侧运算对象动态类型均为 `WordQuery` 实际调用 `WordQuery::rep()`
>
> (c)
>
> 1. `q.eval()` 在函数体中调用 `q->eval()`
> 2. q 的动态类型是 OrQuery ，通过动态绑定调用 `OrQuery::eval()`
> 3. `QueryResult OrQuery::eval(const TextQuery &) const override` 被调用，返回查询结果 QueryResult
