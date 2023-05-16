下面的 Sales_data 输入运算符存在错误吗？
如果有，请指出来。对于这个输入运算符，如果仍然给定上个练习的输入，将发生什么情况？

```cpp
istream &operator>>(istream &in, Sales_data &s)
{
    double price;
    in >> s.book_No >> s.unites_sold >> price;
    s.revenue = s.unites_sold * price;
    return in;
}
```

> 答：有错误，输入运算符没有检查输入流 in 的合法性。情况与上个练习相同。
