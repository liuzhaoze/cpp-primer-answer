在调用 factorial 函数时，为什么传入的值是 val - 1 而非 val-- ？

```c
int factorial(int val)
{
    if (val > 1)
        return factorial(val - 1) * val;
    
    return 1;
}
```

> 答：使用 val-- 实际传入的是减之前的值。数值没变。
