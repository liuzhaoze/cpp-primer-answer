在下列 throw 语句中异常对象的类型是什么？

```cpp
range_error r("error"); throw r;  // (a)
exception *p = &r;      throw *p; // (b)
```

如果将 (b) 中的 throw 语句写成了 `throw p` 将发生什么情况？

> 答：  
> (a) range_error 类  
> (b) exception 类
>
> 会发生运行时错误，因为 p 指向的对象可能会在栈展开的过程中销毁。
