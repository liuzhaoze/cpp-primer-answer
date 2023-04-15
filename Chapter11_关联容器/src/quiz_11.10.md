可以定义一个 `vector<int>::iterator` 到 `int` 的 map 吗？  
`list<int>::iterator` 到 `int` 的 map 呢？  
对于两种情况，如果不能，解释为什么。

> 答：  
> 可以定义 `vector<int>::iterator` 到 `int` 的 map ，因为容器连续存储，其迭代器可以比较大小，定义了 `<` 运算符  
> 不能定义 `list<int>::iterator` 到 `int` 的 map ，因为容器链式存储，其迭代器比较大小没有意义，没有定义 `<` 运算符
