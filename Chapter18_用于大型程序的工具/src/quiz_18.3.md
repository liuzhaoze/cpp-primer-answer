要想让上面的代码在发生异常时能正常工作，有两种解决方案。请描述这两种方法并实现它们。

> 答：
>
> 1. 将内置指针封装到一个类里面，并定义析构函数释放该指针指向的内存
> 2. 使用智能指针代替内置指针

```cpp
// 方法 1
struct intArray
{
    int *p;

    intArray() : p(nullptr) { }
    explicit intArray(std::size_t n) : p(new int[n]) { }
    ~intArray() { delete [] p; }
};
intArray p(v.size());

// 方法 2
std::shared_ptr<int> p(new int[v.size()], [](int *p) { delete [] p; });
```
