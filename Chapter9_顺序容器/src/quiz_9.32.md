下面的程序中，像下面语句这样调用 insert 是否合法？
如果不合法为什么？

```cpp
vector<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
auto iter = vi.begin();

while (iter != vi.end()) {
    if (*iter % 2) {
        iter = vi.insert(iter, *iter);
        iter += 2;
    }
    else {
        iter = vi.erase(iter);
    }
}
```

将 `iter = vi.insert(iter, *iter); iter += 2;`  
改为 `iter = vi.insert(iter, *iter++);`

> 答：不合法。iter 会始终指向新添加的元素 1 ，从而不断插入元素 1 ，程序陷入死循环。
