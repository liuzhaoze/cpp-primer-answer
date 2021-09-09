下面的程序合法吗？如果不合法，你准备如何修改？
```c
vector<int> ivec;
ivec[0] = 42;
```

> 答：不合法。应改为：
```c
vector<int> ivec(1);
ivec[0] = 42;
```
