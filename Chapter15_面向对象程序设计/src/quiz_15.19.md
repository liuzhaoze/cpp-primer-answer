假设[练习 15.18](./quiz_15.18.md) 中的每个类
`Pub_Derv Prot_Derv Priv_Derv Derived_from_Public Derived_from_Protected Derived_from_Private`
都有如下形式的成员函数：

```cpp
void memFcn(Base &b) { b = *this; }
```

对于每个类，分别判断上面的函数是否合法。

> 答：
>
> 在**派生类**的代码中，公有继承、受保护的继承、私有继承都支持派生类向基类的转换  
> `Pub_Derv Prot_Derv Priv_Derv` 都合法
>
> 在**派生类的派生类**的代码中，只有公有继承、受保护的继承支持派生类向基类的转换  
> `Pub_Derv Prot_Derv`合法，`Priv_Derv` 不合法
