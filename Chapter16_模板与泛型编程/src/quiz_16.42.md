对下面每个调用，确定 T 和 val 的类型：

```cpp
template <typename T> void g(T &&val);
int i = 0;
const int ci = i;

g(i);      // (a)
g(ci);     // (b)
g(i * ci); // (c)
```

> 答：  
> (a) 实参是左值，T 推断为 `int &` ，val `int & &&` 引用折叠后为 `int &`  
> (b) 实参是左值，T 推断为 `const int &` ，val `const int & &&` 引用折叠后为 `const int &`  
> (c) 实参是右值，T 推断为 `int` ，val 为 `int &&`
