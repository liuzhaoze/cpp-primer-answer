# 14.7 成员访问运算符

箭头运算符必须是类的成员。  
解引用运算符通常是类的成员，但并非必须。

解引用运算符返回对应类的引用。  
箭头运算符返回对应类的指针或者返回一个定义了 `operator->` 的对象。

解引用和箭头运算符都是 const 成员，因为返回一个元素并不改变对象的状态。

例：

```cpp
std::string &StrBlobPtr::operator*() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

std::string *StrBlobPtr::operator->() const
{
    return & this->operator*(); // 箭头运算符实际上将工作交给解引用运算符完成
}
```

`operator*` 可以被定义成任何操作，但是 `operator->` 只能被定义成获取成员这一种操作。

表达式 `point->mem` 的等价形式根据 point 的类型有所不同：

1. 如果 `point` 是指针，则 `->` 调用内置的箭头运算符；首先解引用 `point` 指针，然后从得到的对象中获得指定的成员 `mem` ；等价于 `(*point).mem`
2. 如果 `point` 是定义了 `operator->` 的类的对象，则调用 `point.operator->()` 得到一个返回值：
   * 如果该返回值是指针，则执行步骤 1 ，得到指针所指对象的成员
   * 如果该返回值不是指针，其所属的类定义了 `operator->` ，则用该返回值重复步骤 2 ，直到得到的返回值是指针，然后执行步骤 1
   * 如果该返回值既不是指针，也没有定义 `operator->` ，则会发生错误

## 练习

* [练习 14.30](../src/quiz_14.30.md)
* [练习 14.31](../src/quiz_14.31.md)
* [练习 14.32](../src/quiz_14.32.cpp)
