从下面的几种改进中选择一种，设计并实现它：

(a) 按句子查询并打印单词，而不再是按行打印  
(b) 引入一个历史系统，用户可以按编号查阅之前的某个查询，并可以在其中增加内容或者将其与其他查询组合  
(c) 允许用户对结果作出限制，比如从给定范围的行中挑出匹配的进行显示

> 答：
>
> (a) 略
>
> (b)
>
> * [QueryHistory.hpp](./text_query_program/QueryHistory.hpp)
> * [QueryHistory.cpp](./text_query_program/QueryHistory.cpp)
>
> (c)
>
> * [QueryResult.hpp](./text_query_program/QueryResult.hpp) 对 print 函数进行重载
