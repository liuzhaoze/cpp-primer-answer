有些情况下我们希望提供 cin 作为接受 istream& 参数的构造函数的默认实参，请声明这样的构造函数。

> 答：

```c
Sales_data(std::istream &is = std::cin) { read(is, *this); }
```
