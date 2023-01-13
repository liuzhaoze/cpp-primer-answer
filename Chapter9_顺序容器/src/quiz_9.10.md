下面四个对象分别是什么类型？

```cpp
vector<int> v1;
const vector<int> v2;
auto it1 = v1.begin(), it2 = v2.begin();
auto it3 = v1.cbegin(), it4 = v2.cbegin();
```

> 答:  
> it1 是 `vector<int>::iterator` 类型  
> it2 是 `vector<int>::const_iterator` 类型  
> it3 是 `vector<int>::const_iterator` 类型  
> it4 是 `vector<int>::const_iterator` 类型  
