假定 `v` 是一个 `vector<double>` ，那么调用 `accumulate(v.cbegin(), v.cend(), 0)` 有何错误（如果存在的话）？

> 答：不会发生编译错误，double 类型会转化成 int 类型进行累加。
