解释 set 和 list 的区别。你如何选择使用哪个？

> 答：

||list|set|
|:-:|:-:|:-:|
|搜索效率|O(n)|O(log(n))|
|增加/删除元素效率|O(1)|O(log(n))|
|元素逻辑有序性|可有可无|无序|
|元素存储有序性|可有可无|按升序存储|
|元素唯一性|元素可以重复|元素一定唯一|
