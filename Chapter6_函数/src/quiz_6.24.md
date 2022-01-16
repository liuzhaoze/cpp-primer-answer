描述下面这个函数的行为。如果代码中存在问题，请指出并改正。

```c
void print(const int ia[10])
{
    for (size_t i = 0; i != 10; ++i)
        cout << ia[i] << endl;
}
```

> 答：函数将数组 ia 中的元素依次打印出来。
