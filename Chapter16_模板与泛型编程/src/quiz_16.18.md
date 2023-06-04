解释下面每个函数模板声明并指出他们是否非法。更正你发现的每个错误。

```cpp
template <typename T, U, typename V> void f1(T, U, V); // (a)
template <typename T> T f2(int &T); // (b)
inline template <typename T> T foo(T, unsigned int *); // (c)
template <typename T> f4(T, T); // (d)

typedef char Ctype;
template <typename Ctype> Ctype f5(Ctype a); // (e)
```

> 答：
>
> (a) 错误：类型参数前必须添加 typename `<typename T,typename U, typename V>`  
> (b) 错误：模板定义中的变量名不能与模板参数名相同 `f2(int &)`  
> (c) 错误：inline 应该在模板参数列表之后，返回类型之前 `template <typename T> inline T foo(T, unsigned int *);`  
> (d) 错误：没有指出返回类型 `template <typename T> T f4(T, T);`  
> (e) 合法，但要注意 char 定义为 Ctype 在函数模板的作用域中被隐藏了
