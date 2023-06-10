# 17.2 bitset 类型

> 本章术语：
>
> * 低位（low-order）：编号为 0 的二进制位
> * 高位（high-order）：编号为总位数减一的二进制位

bitset 类型定义在头文件 `<bitset>` 中。

## 17.2.1 定义和初始化 bitset

bitset 类型具有固定的大小。必须用常量表达式指明其大小。

初始化 bitset 的方法：

* `bitset<n> b;` ：b 有 n 位，每一位都为 0 ；此构造函数是 constexpr
* `bitset<n> b(u);` ：b 是一个 unsigned long long 的 u 的低 n 位的拷贝；如果 b 的长度大于 u ，则高位超出的部分被置为 0 ；此构造函数是 constexpr
* `bitset<n> b(s, pos, m, zero, one);` ：b 是 string s 从位置 pos 开始 m 个字符的拷贝。s 只能包含字符 `zero` 或 `one` ，如果包含其他字符，构造函数会抛出 invalid_argument 异常。字符 `zero` 对应 b 中的 0 ，字符 `one` 对应 b 中的 1 。pos 默认为 0 ，m 默认为 `string::npos` ，`zero` 默认为 `'0'` ，`one` 默认为 `'1'` （此构造函数是 explicit 的）
* `bitset<n> b(cp, pos, m, zero, one);` ：与上一个构造函数相同，但是 cp 指向字符数组。如果未提供 m ，cp 必须指向 C 风格字符串；如果提供 m ，cp 必须从 pos 开始存在 m 个 `zero` 或 `one` 字符 （此构造函数是 explicit 的）

如果 string 包含的字符数比 bitset 少，则 bitset 多出的高位部分置为 0 。

```cpp
string str("1111000011001100");
bitset<32> bitvec(str, 5, 4); // 从 str[5] 开始的四个二进制位
bitset<32> bitvec(str, str.size() - 4); // 从 str 倒数第四个开始，直到末尾的所有二进制位（m 默认为 string::npos）
```

字符串索引从左到右从 0 开始编号；bitset 从右到左从 0 开始编号。  
二进制位的相对位置不变，初始化的是 bitset 的低位。

## 17.2.2 bitset 操作

* `b.any()` ：存在置位的二进制位时，返回 true ；否则返回 false
* `b.all()` ：所有二进制位置位时，返回 true ；否则返回 false
* `b.none()` ：所有二进制位复位时，返回 true ；否则返回 false
* `b.count()` ：置位的二进制位数
* `b.size()` ：返回 b 的长度（constexpr 函数）
* `b.test(pos)` ：pos 指向的二进制位置位，返回 true ；否则返回 false
* `b.set()` ：将所有二进制位置位
* `b.set(pos, v)` ：将 pos 指向的二进制位设置为 bool 值 v ，v 默认为 true
* `b.reset()` ：将所有二进制位复位
* `b.reset(pos)` ：将 pos 指向的二进制位复位
* `b.flip()` ：翻转所有二进制位的状态
* `b.flip(pos)` ：翻转 pos 指向的二进制位
* `b[pos]` ：若 b 是 const 的，则返回 pos 指向的二进制位对应的 bool 值；若 b 不是 const 的，则返回一个指向该二进制位的“引用”，可以对该位进行赋值
* `b.to_ulong()` ：将二进制转化为对应的 unsigned long 十进制数，超出 unsigned long 能表示的范围时抛出 overflow_error 异常
* `b.to_ullong()` 将二进制转化为对应的 unsigned long long 十进制数，超出 unsigned long long 能表示的范围时抛出 overflow_error 异常
* `b.to_string(zero, one)` ：将二进制转换为字符串，0 对应字符 `zero` ，1 对应字符 `one` ；`zero` 默认为 `'0'` ，`one` 默认为 `'1'`
* `os << b` ：将二进制位打印为字符 `'0'` 或 `'1'` ，输出到 os
* `is >> b` ：从 is 中读取字符 `'0'` 或 `'1'` 存入 b ，当下一个字符不是 `'0'` 或 `'1'` 时，或者已经读入 `b.size()` 个位时，停止读取（先将输入读入到临时的 string ，然后再用 string 初始化 bitset）

```cpp
// bitvec 是非 const 的
bitvec[0] = 0;          // 将第一位复位
bitvec[31] = bitvec[0]; // 最后一位的状态设置为与第一位相同
bitvec[0].filp();       // 翻转第一位
~bitvec[0];             // 翻转第一位
bool b = bitvec[0];     // 读取第一位的状态
```

## 练习

* [练习 17.9](../src/quiz_17.9.md)
* [练习 17.10](../src/quiz_17.10.cpp)
* [练习 17.11](../src/quiz_17.11.md)
* [练习 17.12](../src/quiz_17.12.cpp)
* [练习 17.13](../src/quiz_17.13.cpp)
