当我们将一个 StrBlob 赋值给另一个 StrBlob 时，会发生什么？赋值 StrBlobPtr 呢？

> 答：StrBlob 和 StrBlobPtr 都会拷贝对应的非 static 成员。  
> 拷贝 `shared_ptr<vector<string>>` 时，引用计数加 1 ；  
> 拷贝 `weak_ptr<vector<string>>` 时，引用计数不变。
