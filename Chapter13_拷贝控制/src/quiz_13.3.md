当我们拷贝一个 [StrBlob](../../lib/StrBlob.hpp) 时，会发生什么？
拷贝一个 StrBlobPtr 呢？

> 答：  
> 当拷贝 StrBlob 时，会拷贝其成员 `shared_ptr<vector<string>>` 对应的引用计数加 1 ；  
> 当拷贝 StrBlobPtr 时，会拷贝其成员 `weak_ptr<vector<string>>` 和 `size_t` 变量，拷贝 weak_ptr 时引用计数不变。
