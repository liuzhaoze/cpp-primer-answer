## 3.4 迭代器介绍

> 本章术语：
> * 迭代器（iterator）
> * 尾后迭代器（off-the-end iterator）：end 成员返回的迭代器。
> * 迭代器运算（iterator arithmetic）


就迭代器而言，其对象是容器中的元素或者 string 对象中的字符。

有效的迭代器或者指向某个元素，或者指向容器中尾元素的下一个位置；其他所有情况都属于无效。

### 3.4.1 使用迭代器
begin 成员负责返回指向第一个元素（或第一个字符）的迭代器。  
end 成员负责返回指向容器（或 string 对象）“尾元素的下一位置（one past the end）”的迭代器。

如果容器为空，则 begin 和 end 返回的是同一个迭代器。都是尾后迭代器。

标准容器迭代器的运算符
```c
*iter
iter->mem  等价于  (*iter).mem
++iter
--iter
iter1 == iter2
iter1 != iter2
```

end 返回的迭代器并不实际指示某个元素，所以不能对其进行递增或解引用的操作。

*建议在 for 循环中终止条件使用* `!=` *而非* `<` 。  
因为所有标准库容器的迭代器都定义了 `==` 和 `!=` ，但是大多数都没有定义 `<` 运算符。

```c
// 迭代器指定的对象可读可写
string::iterator it1;
vector<int>::iterator it2;

// 只能读元素，不能写元素
string::const_iterator it3;
vector<int>::const_iterator it4;
```

如果 vector 对象或 string 对象是一个常量，则只能使用 const_iterator ；  
如果 vector 对象或 string 对象不是常量，那么既能用 const_iterator 也能使用 iterator 。

如果对象是常量， begin 和 end 返回 const_iterator ；如果对象不是常量，则返回 iterator 。

无论 vector 对象（或 string 对象）本身是否是常量， cbegin 和 cend 的返回值都是 const_iterator 。

如果对象只需读操作而无需写操作的话最好使用常量类型（const_iterator）。

*但凡是使用了迭代器的循环体，都不要向迭代器所属的容器添加元素。*

### 3.4.2 迭代器运算
vector 和 string 迭代器支持的运算
```c
iter + n
iter - n
iter1 += n
iter1 -= n
iter1 - iter2
<, <=, >, >=
```

将两个迭代器相减，所得结果是两个迭代器的距离。  
即：右侧的迭代器向前移动多少位置就能追上左侧的迭代器，
其类型是名为 `difference_type` 的带符号整型数。

### 练习
* [练习 3.21](../src/quiz_3.21.cpp)
* [练习 3.22](../src/quiz_3.22.cpp)
* [练习 3.23](../src/quiz_3.23.cpp)
* [练习 3.24](../src/quiz_3.24.cpp)
* [练习 3.25](../src/quiz_3.25.cpp)
* [练习 3.26](../src/quiz_3.26.md)
