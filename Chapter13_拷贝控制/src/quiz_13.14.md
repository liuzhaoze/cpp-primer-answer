假定 numbered 是一个类，它有一个默认构造函数，能为每个对象生成一个唯一的序号，保存在名为 mysn 的数据成员中。
假定 numbered 使用合成的拷贝控制成员，并给出如下函数：

```cpp
void f(numbered s)
{
    cout << s.mysn << endl;
}
```

则下面代码输出什么内容？

```cpp
numbered a, b = a, c = b;
f(a);
f(b);
f(c);
```

> 答：因为使用合成的拷贝控制成员，所以三个函数调用输出的内容相同。
