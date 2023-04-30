给定下面的 new 表达式，你应该如何释放 pa ？

```cpp
int *pa = new int[10];
```

> 答：`delete [] pa;` 。
