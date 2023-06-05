使用与[第一题](./quiz_16.42.md)中相同的三个调用，如果 g 的函数参数声明为 `T` 而不是 `T&&` ，确定 `T` 的类型。
如果 g 的函数参数是 `const T &` 呢？

> 答：
>
> g 的函数参数声明为 `T` ：  
> (a) T 推断为 `int`  
> (b) T 推断为 `int` ，顶层 const 被忽略  
> (c) T 推断为 `int`
>
> g 的函数参数声明为 `const T &` ：  
> (a) T 推断为 `int` ，val 为 `const int &`  
> (b) T 推断为 `int` ，val 为 `const int &`  
> (c) T 推断为 `int` ，val 为 `const int &`
