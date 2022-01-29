在下面这条 if 语句中，条件部分的作用是什么？

```c
if (read(read(cin, data1), data2))
```

> 答：将输入流的内容先赋值给 data1 ，再赋值给 data2 。  
> 总共进行两次输入。
