# 19.6 union ：一种节省空间的类

> 本章术语：
>
> * 联合（union）：一个 union 可以有多个数据成员，但是在任意时刻只有一个数据成员可以有值
> * 匿名 union （anonymous union）
> * 判别式（discriminant）：辨认 union 当前储存的成员是哪一个

union 不能含有引用类型的成员。

union 可以为其成员指定 public 、protected 和 private 保护标记。默认情况下 union 成员都是公有的。

union 可以定义包括构造函数和析构函数在内的成员函数。

union 不能继承自其他类，也不能作为基类使用，不能含有虚函数。

union 通常用来表示一组类型不同的互斥值。为 union 的一个数据成员赋值会令其他数据成员变成未定义的状态。

匿名 union ：

```cpp
union {
    char cval;
    int ival;
    double dval;
};

// 匿名 union 定义所在的作用域内可以直接访问 union 的成员
cval = 'c';
ival = 42;
```

当 union 包含类类型的成员时，应该将 union 内嵌在另一个类中，用这个类管理 union 的类类型成员有关的状态转换。（以 [Token.hpp](../../lib/Token.hpp) 和 [Token.cpp](../../lib/Token.cpp) 为例）

当类类型作为 union 的成员时无法自动销毁，因为析构函数无法确定 union 当前存储的值是什么类型。应该使用上层类手动指定析构函数。

## 练习

* [练习 19.21](../src/quiz_19.21.md)
* [练习 19.22](../src/quiz_19.22.md)
* [练习 19.23](../src/quiz_19.23.md)
* [练习 19.24](../src/quiz_19.24.cpp)
* [练习 19.25](../src/quiz_19.25.cpp)
