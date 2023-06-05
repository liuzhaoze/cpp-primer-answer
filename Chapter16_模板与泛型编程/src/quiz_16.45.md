给定下面的模板，如果我们对一个像 42 这样的字面常量调用 g ，解释会发生什么？
如果我们对一个 int 类型的变量调用 g 呢？

```cpp
template <typename T> void g(T &&val)
{
    vector<T> v;
}
```

> 答：当使用 42 调用 g 时，T 推断为 `int` ，此时可以创建 `vector<int>` ；  
> 当使用 int 型变量调用 g 时，T 推断为 `int &` ，而 `vector<int&>` 是非法的。
