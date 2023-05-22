在下面的加法表达式中分别选用了哪个 operator+ ？
列出候选函数、可行函数以及为每个可行函数的实参执行的类型转换：

```cpp
class SmallInt {
public:
    friend SmallInt operator+(const SmallInt &, const SmallInt &); // 1

private:
    std::size_t val;

public:
    SmallInt(int);
    operator int() const;
};

struct LongDouble {
    LongDouble(double);

    LongDouble operator+(const SmallInt &); // 2
    operator double();
    operator float();
};
LongDouble operator+(LongDouble &, double); // 3

SmallInt si;
LongDouble ld;

ld = si + ld;
ld = ld + si;
```

> 答：  
>
> 候选加法运算符：
>
> 1. SmallInt 的重载 operator+ （非成员）
> 2. LongDouble 的重载 operator+ （成员）
> 3. LongDouble 的重载 operator+ （非成员）
> 4. 内置的加法运算符
>
> `ld = si + ld;` 具有二义性：无法确定使用 SmallInt 的重载 operator+ 还是使用内置版本的加法运算符  
> `ld = ld + si;` 匹配函数 2 ，第一个参数是 LongDouble 类，第二个参数是 SmallInt 类，都是精确匹配
