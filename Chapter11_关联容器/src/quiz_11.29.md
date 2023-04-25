如果给定的关键字不在容器中，upper_bound 、lower_bound 和 equal_range 分别会返回什么？

> 答：  
> upper_bound 和 lower_bound 会返回一个迭代器，指向不影响容器中元素顺序的插入位置；  
> equal_range 返回一个含有两个迭代器的 pair ，两个迭代器都指向关键字可以插入的位置。
