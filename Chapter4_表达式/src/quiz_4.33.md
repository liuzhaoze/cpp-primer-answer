说明下面这条表达式的含义。
```c
someValue ? ++x, ++y : --x, --y
```

> 答：  
> 如果 someValue 为真，则 x 和 y 都加 1 ，并返回 y ；  
> 如果 someValue 为假，则 x 和 y 都减 1 ，并返回 y 。
