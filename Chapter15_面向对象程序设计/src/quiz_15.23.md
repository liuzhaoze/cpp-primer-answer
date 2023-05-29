假设[15.6 节](../note/note_15.6.md)的 D1 类需要覆盖它继承而来的 fcn 函数，你应该如何对其进行修改？
如果你修改之后 fcn 匹配了 Base 中的定义，则该节的那些调用语句将如何解析？

> 答：

```cpp
class D1 : public Base {
public:
    int fcn(); // 将形参列表改为空，与 Base 的 fcn 一致，是虚函数，覆盖了 Base 中的 fcn
    virtual void f();
};
```

> `bp2->fcn();` 调用发生了改变：虚调用，动态绑定，运行时调用 D1::fcn()（D1 覆盖了虚函数）
