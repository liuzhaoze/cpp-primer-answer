解释下列声明的含义，在它们当中存在错误吗？
如果有，请指出来并说明错误的原因。

```cpp
class CADVehicle : public CAD, Vehicle { ... };          // (a)
class DblList : public List, public List { ... };        // (b)
class iostream : public istream, public ostream { ... }; // (c)
```

> 答：  
> (a) 正确：公有继承 CAD ，私有继承 Vehicle ，Vehicle 的所有成员都是 private 的  
> (b) 错误：在一个派生列表中，同一个基类只能出现一次  
> (c) 正确：同时公有继承了 istream 和 ostream
