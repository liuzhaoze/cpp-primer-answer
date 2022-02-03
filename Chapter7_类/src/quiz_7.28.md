如果 move 、 set 和 display 函数的返回类型不是 Screen& 而是 Screen ，则在上一个练习中将会发生什么情况？

> 答：  
> 第一次输出 `XXXXXXXXXXXXXXXXXXXX#XXXX`  
> 第二次输出 `XXXXXXXXXXXXXXXXXXXXXXXXX`  
> 第一次的操作是在 myScreen 的副本上进行的，实际上并没有改变 myScreen 中成员函数的值。
