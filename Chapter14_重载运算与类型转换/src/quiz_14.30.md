为你的 StrBlobPtr 类和在 12.1.6 节练习 12.22 中定义的 ConstStrBlobPtr 类分别添加解引用运算符和箭头运算符。
注意：因为 ConstStrBlobPtr 的数据成员指向 const vector ，所以 ConstStrBlobPtr 中的运算符必须返回常量引用。

> 答：见 [StrBlob.hpp](../../lib/StrBlob.hpp) 和 [StrBlob.cpp](../../lib/StrBlob.cpp) 。
