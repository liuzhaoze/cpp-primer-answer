为下面的函数编写函数声明，从给定的名字中推测函数具备的功能。  
(a) 名为 `compare` 的函数，返回布尔值，两个参数都是 `matrix` 类的引用。  
(b) 名为 `change_val` 的函数，返回 `vector<int>` 的迭代器，有两个参数：一个是 `int` ，另一个是 `vector<int>` 的迭代器。

> 答：

```c
bool compare(matrix &a, matrix &b); // 比较两个矩阵是否相同
vector<int>::iterator change_val(int, vector<int>::iterator); // 改变某个向量的值
```
