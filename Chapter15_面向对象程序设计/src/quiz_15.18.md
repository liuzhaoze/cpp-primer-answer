假设给定了下面几个类，同时已知每个对象的类型如注释所示，判断下面的哪些赋值语句是合法的。
解释那些不合法的语句为什么不被允许：

```cpp
class Base {
private:
    char priv_mem;

protected:
    int prot_mem;

public:
    void pub_mem();
};

class Sneaky : public Base {
public:
    friend void clobber(Sneaky &);

private:
    int j;
};
void clobber(Sneaky &s) { s.j = s.prot_mem = 0; }

struct Pub_Derv : public Base {
    int f() { return prot_mem; }
};

struct Priv_Derv : private Base {
    int ff() const { return prot_mem; }
};

struct Derived_from_Public : public Pub_Derv {
    int use_base() { return prot_mem; }
};

struct Derived_from_Protected : public Prot_Derv {

};

struct Derive_from_Private : public Priv_Derv {

};
```

```cpp
Base *p = &d1; // d1 是 Pub_Derv
p = &d2; // d2 是 Priv_Derv
p = &d3; // d3 是 Prot_Derv

p = &dd1; // dd1 是 Derived_from_Public
p = &dd2; // dd2 是 Derive_from_Private
p = &dd3; // dd3 是 Derived_from_Protected
```

> 答：在用户代码中，只有公有继承的类允许向基类转换  
> Pub_Derv 向基类转换：公有继承允许  
> Priv_Derv 向基类转换：私有继承不允许  
> Prot_Derv 向基类转换：受保护的继承不允许  
> Derived_from_Public 向基类转换：允许  
> Derive_from_Private 向基类转换：不允许  
> Derived_from_Protected 向基类转换：不允许
