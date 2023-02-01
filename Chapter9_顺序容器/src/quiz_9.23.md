在本节第一个程序中，若 c.size() 为 1 ，则 val 、 val2 、 val3 和 val4 的值会是什么？

```cpp
if (!c.empty()) {
    auto val = *c.begin(), val2 = c.front();

    auto last = c.end();
    auto val3 = *(--last);
    auto val4 = c.back();
}
```

> 答：val 、 val2 、 val3 和 val4 都是 c 中唯一的那个元素的拷贝。
