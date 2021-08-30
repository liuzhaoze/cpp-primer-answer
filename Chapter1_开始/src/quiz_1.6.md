解释下面程序片段是否合法。
```c
std::cout << "The sum of " << v1;
          << " and " << v2;
          << " is " << v1 + v2 << std::endl;
```
如果程序是合法的，它输出什么？如果程序不合法，原因何在？应该如何修正？

> 答：程序不合法。第二行和第三行中，第一个运算符 `<<` 没有左侧运算对象。应改为：

```c
std::cout << "The sum of " << v1;
std::cout << " and " << v2;
std::cout << " is " << v1 + v2 << std::endl;
```
