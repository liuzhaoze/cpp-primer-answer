已知有如下声明：

```c
void manip(int, int);
double dobj;
```

请指出下列调用中每个类型转换的等级。

(a) `manip('a', 'z');`  
(b) `manip(55.4, dobj);`

> 答：  
> (a) 第三级：通过类型提升实现的匹配。  
> (b) 第四级：通过算术类型转换实现的匹配。
