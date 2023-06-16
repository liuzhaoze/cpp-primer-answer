当在指定的位置发生了异常时将出现什么情况？

```cpp
void exercise(int *b, int *e)
{
    vector<int> v(b, e);
    int *p = new int[v.size()];
    ifstream in("ints");
    // 此处发生异常
}
```

> 答：标准库 vector 和 ifstream 对象会正常调用析构函数销毁，而 p 指向的内存不会自动释放，会发生内存泄漏。
