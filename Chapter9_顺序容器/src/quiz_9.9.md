begin 和 cbegin 两个函数有什么不同？

> 答：cbegin 返回 const_iterator；  
> begin 返回 iterator ，只有当容器为 const 时，返回 const_iterator 。
