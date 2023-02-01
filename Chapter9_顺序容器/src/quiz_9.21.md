如果我们将第 308 页中使用 insert 返回值将元素添加到 list 中的循环程序改写为将元素插入到 vector 中，分析循环将如何工作。

```cpp
vector<string> vec;
auto iter = vec.begin();
while (cin >> word)
    iter = vec.insert(iter, word);
```

> 答：在循环之前，我们将 iter 初始化为 vec.begin()。
> 第一次调用 insert 会将我们刚刚读入的 string 插入到 iter 所指向的元素之前的位置。
> insert 返回的迭代器刚好指向这个新元素。
> 我们将此迭代器赋予 iter 并重复循环，读取下一单词。
> 只要继续有单词读入，每步 while 循环就会将一个新元素插入到 iter 之前，并将 iter 改变为新加入元素的位置。
> 此元素为（新的）首元素。因此，每步循环将一个新元素插入到 vector 首元素之前的位置。
