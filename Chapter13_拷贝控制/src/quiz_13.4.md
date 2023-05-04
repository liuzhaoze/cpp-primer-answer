假定 Point 是一个类类型，它有一个 public 的拷贝构造函数，指出下面程序片段中哪些地方使用了拷贝构造函数：

```cpp
Point global;
Point foo_bar(Point arg)
{
    Point local = arg, *heap = new Point(global);
    *heap = local;
    Point pa[4] = {local, *heap};
    return *heap;
}
```

> 答：
>
> * 形参 arg 的初始化调用了拷贝构造函数
> * local 的初始化调用了拷贝构造函数
> * heap 的初始化调用了拷贝构造函数
> * 数组 pa 的前两个元素的初始化调用了拷贝构造函数
> * 函数返回非引用类型调用了拷贝构造函数
