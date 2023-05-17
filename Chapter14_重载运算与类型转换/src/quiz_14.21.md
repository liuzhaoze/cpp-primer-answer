编写 Sales_data 类的 + 和 += 运算符，使得 + 执行实际的加法操作而 += 调用 + 。
相比于 14.3 节和 14.4 节对这两个运算符的定义，本题的定义有何缺点？试讨论之。

14.3 节和 14.4 节对这两个运算符的定义：

```cpp
Sales_data &Sales_data::operator+=(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum += rhs;
    return sum;
}
```

> 答：调用 + 的 += 运算符：

```cpp
Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum;
    sum.units_sold = lhs.units_sold + rhs.units_sold;
    sum.revenue = lhs.revenue + rhs.revenue;
    return sum;
}

Sales_data &Sales_data::operator+=(const Sales_data &rhs)
{
    Sales_data lhs = *this;
    *this = lhs + rhs;
    return *this;
}
```

> 上述定义的缺点：在调用 += 运算符时会产生不必要的 Sales_data 临时对象。
