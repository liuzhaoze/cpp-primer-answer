假设我们已经定义了如下所示的 SmallInt ，判断下面的加法表达式是否合法。
如果合法，使用了哪个加法运算符？如果不合法，应该怎样修改代码才能使其合法？

```cpp
class SmallInt {
public:
    friend SmallInt operator+(const SmallInt &, const SmallInt &);

private:
    std::size_t val;

public:
    SmallInt(int);
    operator int() const;
};

SmallInt si;
double d = si + 3.14;
```

> 答：不合法，在重载的加法运算符和内置的加法运算符之间产生二义性。  
> 修改：`double d = si + SmallInt(3.14);`
