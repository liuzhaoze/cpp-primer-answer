如果 factorial 函数的停止条件如下所示，将发生什么情况？  
`if (val != 0)`

```c
int factorial(int val)
{
    if (val > 1)
        return factorial(val - 1) * val;
    
    return 1;
}
```

> 答：当 val 是负数时，函数将永远递归下去。
