对下面每条带标签的语句，解释发生了什么样的实例化（如果有的话）。
如果一个模板被实例化，解释为什么；如果未实例化，解释为什么没有。

```cpp
template <typename T> class Stack { };

void f1(Stack<char>);   // (a)

class Exercise {
    Stack<double> &rsd; // (b)
    Stack<int> si;      // (c)
};

int main() {
    Stack<char> *sc;    // (d)
    f1(*sc);            // (e)

    int iObj = sizeof(Stack<string>); // (f)
}
```

> 答：  
> (a) `Stack<char>` 实例化：第一次使用  
> (b) `Stack<double>` 实例化：第一次使用  
> (c) `Stack<int>` 实例化：第一次使用  
> (d) 未实例化：(a) 已经完成实例化  
> (e) 未实例化：仅仅是函数调用  
> (f) `Stack<string>` 实例化：第一次使用
