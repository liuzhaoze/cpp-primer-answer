当一个 StrBlob 对象销毁时会发生什么？一个 StrBlobPtr 对象销毁时呢？

> 答：StrBlob 销毁时，shared_ptr 的引用计数会减 1 ；当引用计数减为 0 时，shared_ptr 所指向的 vector 会被销毁。  
> StrBlobPtr 销毁时，会销毁 weak_ptr 和 size_t 两个成员。
