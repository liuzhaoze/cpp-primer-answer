给定[上一题](./quiz_15.13.md)中的类以及下面这些对象，说明在运行时调用哪个函数：

```cpp
base bObj;          derived dObj;
base *bp1 = &bObj, *bp2 = &dObj;
base &br1 = bObj,  &br2 = dObj;

bObj.print(); // (a)
dObj.print(); // (b)
bp1->name();  // (c)
bp2->name();  // (d)
br1.print();  // (e)
br2.print();  // (f)
```

> 答：  
> (a) `base::print()`  
> (b) `derived::print()`  
> (c) `base::name()`  
> (d) `base::name()`  
> (e) `base::print()`  
> (f) `derived::print()`  
