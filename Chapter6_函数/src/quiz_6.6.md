说明形参、局部变量以及局部静态变量的区别。
编写一个程序，同时用到这三种形式。

> 答：  
> **局部变量**：定义在块中的变量。  
> **形参**：声明在函数形参列表中的局部变量。  
> **局部静态变量**：第一次定义后不会随着函数的结束而销毁。只有在程序结束运行后才销毁。

```c
size_t count_add(int n)       // n 是形参
{
    static size_t ctr = 0;    // ctr 是局部静态变量
    ctr += n;
    return ctr;
}

int main()
{
    for (size_t i = 0; i != 10; ++i)  // i 是局部变量
      cout << count_add(i) << endl;

    return 0;
}
```
