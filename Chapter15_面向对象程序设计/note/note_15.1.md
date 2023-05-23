# 15.1 OOP：概述

> 本章术语：
>
> * 面向对象程序设计（object-oriented programming）：数据抽象、继承、动态绑定
> * 继承（inheritance）
> * 基类（base class）：负责定义在层次关系中所有类共同拥有的成员
> * 派生类（derived class）：每个派生类定义各自特有的成员
> * 虚函数（virtual function）：基类希望它的派生类各自定义合适自身的版本的函数
> * 类派生列表（class derivation list）：指明派生类从哪个（哪些）基类继承而来
> * 动态绑定（dynamic binding）：允许使用同一段代码处理基类和派生类对象
> * 运行时绑定（run-time binding）：动态绑定的别称

基类 Quote：

```cpp
class Quote
{
public
    std::string isbn() const;
    virtual double net_price(std::size_t n) const; // 虚函数：派生类必须定义自己的版本
};
```

派生类 Bulk_quote：

```cpp
class Bulk_quote : public Quote // 派生类列表：从 Quote 基类继承，public 表示 Bulk_quote 类完全可以当作 Quote 类使用
{
public:
    double net_price(std::size_t) const override; // 定义自己版本的基类虚函数
};
```

当我们使用**基类的引用（或指针）**调用一个**虚函数**时，将发生动态绑定：

```cpp
double print_total(ostream &os, const Quote &item, size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn()
       << " number sold: " << n
       << " total due: " << ret << endl;

    return ret;
}

Quote basic;
Bulk_quote bulk;
print_total(cout, basic, 20); // 调用 Quote 的 net_price
print_total(cout, bulk, 20); // 调用 Bulk_quote 的 net_price
```
