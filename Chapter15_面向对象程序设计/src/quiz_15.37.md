如果在派生类中含有 `shared_ptr<Query_base>` 类型的成员而非 `Query` 类型的成员，则你的类需要做出怎样的改变？

> 答：需要使用 `->` 运算符而非 `.` 运算符来调用成员函数。
