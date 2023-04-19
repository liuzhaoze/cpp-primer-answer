假定 c 是一个 string 的 multiset ，v 是一个 string 的 vector ，解释下面的调用。
指出每个调用是否合法：

(a) `copy(v.begin(), v.end(), inserter(c, c.end()));`  
(b) `copy(v.begin(), v.end(), back_inserter(c));`  
(c) `copy(c.begin(), c.end(), inserter(v, v.end()));`  
(d) `copy(c.begin(), c.end(), back_inserter(v));`  

> 答：  
> (a) 合法，将 v 的元素插入到 c 的末尾  
> (b) 非法，multiset 没有 push_back 方法，因此没有 back_inserter  
> (c) 合法，将 c 的元素插入到 v 的末尾  
> (d) 合法，将 c 的元素插入到 v 的末尾
