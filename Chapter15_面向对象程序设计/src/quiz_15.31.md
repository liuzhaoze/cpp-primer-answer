已知 s1 、s2 、s3 和 s4 都是 string ，判断下面的表达式分别创建了什么样的对象：

(a) `Query(s1) | Query(s2) & ~ Query(s3);`  
(b) `Query(s1) | ( Query(s2) & ~ Query(s3) );`  
(c) `( Query(s1) & (Query(s2)) | ( Query(s3) & Query(s4) ) );`

> 答：  
> (a) 先通过接受 string 的构造函数创建 WordQuery ，然后按照运算顺序创建了 NotQuery 、OrQuery 和 AndQuery  
> (b) 先通过接受 string 的构造函数创建 WordQuery ，然后按照运算顺序创建了 NotQuery 、AndQuery 和 OrQuery  
> (c) 先通过接受 string 的构造函数创建 WordQuery ，然后按照运算顺序创建了 AndQuery 、AndQuery 和 OrQuery
