请指出下列函数哪个有错误，为什么？应该如何修改这些错误？

(a)

```c
int f() {
    string s;
    // ...
    return s;
}
```

(b)

```c
f2 (int i) { /* ... */ }
```

(c)

```c
int calc(int v1, int v1) { /* ... */ }
```

(d)

```c
double square(double x) return x * x;
```

> 答：  
> (a) 返回值类型不匹配， int 应改为 string 。  
> (b) 没有为函数声明返回类型。  
> (c) 形参列表中的参数名相同。  
> (d) 函数体需要用花括号括起来。
