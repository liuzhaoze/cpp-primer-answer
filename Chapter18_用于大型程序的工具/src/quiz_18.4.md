对于 [18.1.5 小节](../note/note_18.1.md)中的继承体系，说明下面的 try 块有何错误并修改它。

```cpp
try {
    // 使用 C++ 标准库
}
catch (exception) {
    // ...
}
catch (const runtime_error &re) {
    // ...
}
catch (overflow_error eobj) {
    // ...
}
```

> 答：应该把继承链最底端的类放在前面，继承链最顶端的类放在后面。上述 try 块的 catch 语句顺序正好相反。应改为：

```cpp
try {
    // 使用 C++ 标准库
}
catch (overflow_error eobj) {
    // ...
}
catch (const runtime_error &re) {
    // ...
}
catch (exception) {
    // ...
}
```
