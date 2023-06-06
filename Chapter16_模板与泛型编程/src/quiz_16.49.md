解释下面每个调用会发生什么：

```cpp
template <typename T> void f(T);         // [1]
template <typename T> void f(const T *); // [2]
template <typename T> void g(T);         // [3]
template <typename T> void g(T *);       // [4]

int i = 42;
int *ip = &i;
const int ci = 0;
const int *cip = &ci;

g(42); g(ip); g(ci); g(cip);
f(42); f(ip); f(ci); f(cip);
```

> 答：  
> `g(42)` 只有 [3] 可行，[4] 类型不匹配无法实例化  
> `g(ip)` [4] 比 [3] 更特例化，匹配 [4]  
> `g(ci)` 只有 [3] 可行，[4] 类型不匹配无法实例化  
> `g(cip)` [4] 比 [3] 更特例化，匹配 [4]  
> `f(42)` 只有 [1] 可行，[2] 类型不匹配无法实例化  
> `f(ip)` [1] `f(int *)` [2] `f(const int *)` 精确匹配选择 [1]  
> `f(ci)` 只有 [1] 可行，[2] 类型不匹配无法实例化  
> `f(cip)` [1] `f(const int *)` [2] `f(const int *)` [2] 比 [1] 更特例化，匹配 [2]
