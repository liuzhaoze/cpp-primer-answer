举一个形参应该是引用类型的例子，再举一个形参不能是引用类型的例子。

> 答：

形参应该是引用的例子：

```c
void reset(int &i)
{
    i = 0;
}
```

形参不应该是引用的例子：

```c
void print(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    for (std::vector<int>::iterator iter = begin; iter != end; ++iter)
        std::cout << *iter << std::endl;
}
```
