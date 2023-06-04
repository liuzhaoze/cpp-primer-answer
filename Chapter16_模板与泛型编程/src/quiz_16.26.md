假设 NoDefault 是一个没有默认构造函数的类，我们可以显式实例化 `vector<NoDefault>` 吗？
如果不可以，解释为什么？

> 答：不可以。
> 当 `vector<NoDefault>` 希望被显式实例化时，`NoDefault` 类必须能用于模板 `vector` 的所有成员函数。
> 而 `vector` 中有一个成员函数 `vector(size_type n)` 的实例化要求模板实参支持默认初始化。
> 因为没有默认构造函数的 `NoDefault` 类无法默认初始化，所以无法显式实例化 `vector<NoDefault>` 。
