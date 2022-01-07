说明下列循环的含义并改正其中的错误。

(a)

```c
do
    int v1, v2;
    cout << "Please enter two numbers to sum:";
    if (cin >> v1 >> v2)
        cout << "Sum is: " << v1 + v2 << endl;
while (cin);
```

(b)

```c
do {
    // ...
} while (int ival = get_response());
```

(c)

```c
do {
    int ival = get_response();
} while (ival);
```

> 答：  
> (a) 循环体没有用花括号括起来。  
> (b) 不允许在条件部分定义变量。  
> (c) 条件使用的变量必须定义在循环体之外。
