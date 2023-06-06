假定 s 是一个 string ，解释调用 `svec.emplace_back(s)` 会发生什么。

> 答：s 是一个左值，emplace_back 会将 s 的值拷贝到 svec 的动态内存中。
