什么情况下，下面的 while 循环会终止？

```cpp
while (cin >> i) /* ... */
```

> 答：只要 badbit、failbit、eofbit 有一个为真，while循环就会终止。
