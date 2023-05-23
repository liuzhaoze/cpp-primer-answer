下面哪条声明语句是不正确的？请解释原因。

```cpp
class Base { ... };

class Derived : public Derived { ... }; // (a)
class Derived : private Base { ... };   // (b)
class Derived : public Base;            // (c)
```

> 答：  
> (a) 错误：一个类不能派生它本身  
> (b) 错误：这是派生类的定义，而非声明语句  
> (c) 错误：派生类的声明不包含类派生列表
