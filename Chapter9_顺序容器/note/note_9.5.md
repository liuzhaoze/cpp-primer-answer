# 9.5 额外的 string 操作

## 9.5.1 构造 string 的其他方法

除了[3.2节](../../Chapter3_字符串、向量和数组/note/note_3.2.md)已经介绍过的构造函数，string 类型还支持另外三个构造函数：

* `string s(cp, n);` ：s 是指针 cp 指向的数组中前 n 个字符的拷贝，该数组至少应该包含 n 个字符
* `string s(s1, pos1);` ：s 是 string s1 从下标 pos1 开始的字符的拷贝（若 pos1 > s1.size() 则构造函数抛出 out_of_range 异常）
* `string s(s2, pos2, len2);` ：s 是 string s2 从下标 pos2 开始 len2 个字符的拷贝（若 pos2 > s2.size() 则构造函数抛出 out_of_range 异常；无论 len2 的值是多少，构造函数最多拷贝 s2.size() - pos2 个字符

```cpp
const char *cp = "Hello World!!!"; // 以空字符 '\0' 结尾的数组
char noNull[] = {'H', 'i'};        // 不以空字符 '\0' 结尾

string s1(cp);        // 拷贝 cp 中的字符直到遇到 '\0' ；s1 = "Hello World!!!"
string s2(noNull, 2); // 拷贝 noNull 的前两个字符；s2 = "Hi"
string s3(noNull);    // noNull 没有空字符，行为未定义
string s4(cp + 6, 5); // 从 cp[6] 开始拷贝 5 个字符；s4 = "World"
string s5(s1, 6, 5);  // 从 s1[6] 开始拷贝 5 个字符；s5 = "World"
string s6(s1, 6);     // 从 s1[6] 开始拷贝直到末尾；s6 = "World!!!"
string s7(s1, 6, 20); // 长度大于 s1.size() 时只会拷贝到末尾；s7 = "World!!!"
string s8(s1, 16);    // 抛出 out_of_range 异常
```

子字符串操作：

* `s.substr(pos, n)` ：返回一个 string ，包含 s 中从 pos 开始的 n 个字符的拷贝（ pos 默认值为 0 ，n 默认值为 s.size() - pos ）

```cpp
string s("hello world");
string s1 = s.substr(0, 5);  // s1 = "hello"
string s2 = s.substr(6);     // s2 = "world"
string s3 = s.substr(6, 20); // s3 = "world" 只会拷贝到末尾
string s4 = s.substr(12);    // 抛出 out_of_range 异常
```

## 9.5.2 改变 string 的其他方法

修改 string 的操作总结：

* `s.insert(pos, args)` ：在 pos 之前插入 args 指定的字符（当 pos 是下标时，返回指向 s 的引用；当 pos 是迭代器时，返回指向第一个插入字符的迭代器）
* `s.erase(pos, len)` ：删除从 pos 开始的 len 个字符，如果 len 被省略，则删除从 pos 开始直到 s 末尾的所有字符，返回指向 s 的引用
* `s.assign(args)` ：将 s 中的字符替换为 args 指定的字符，返回指向 s 的引用
* `s.append(args)` ：将 args 指定的字符添加到 s 的末尾，返回指向 s 的引用
* `s.replace(range, args)` ：删除 s 中 range 指定范围内的字符，替换为 args 指定的字符，返回指向 s 的引用

`range` 可用的形式：

1. `pos, len` ：下标和长度所指定的范围
2. `b, e` ：一对指向 s 的迭代器所指定的范围

`args` 可能的形式：

1. `str` ：string 类字符串
2. `str, pos, len` ：str 中从 pos 开始最多 len 个字
3. `cp` ：cp 指向的以空字符结尾的字符数组（ const char *cp ）
4. `cp, len` ：cp 指向的字符数组的前（最多）len 个字符
5. `n, c` ：n 个字符 c
6. `b, e` ：迭代器 b 和 e 指定的范围内的字符
7. `{a, b, c ...}` ：初始化列表

上述 `str` 不能与 s 相同，迭代器 `b` 和 `e` 不能指向 s 。

`append` 和 `assign` 的 `args` 可以使用上述所有 7 种形式。  
`insert` 的 `args` 形式与 `pos` 的类型有关；`replace` 的 `args` 形式与 `range` 的形式有关。

`√` 为可用，`×` 为不可用。
|args 的形式|insert 的 pos 是下标|insert 的 pos 是迭代器|replace 的 range 是下标+长度|replace 的 range 是一对迭代器|
|:-:|:-:|:-:|:-:|:-:|
|`str`|√|×|√|√|
|`str, pos, len`|√|×|√|×|
|`cp`|×|×|√|√|
|`cp, len`|√|×|√|√|
|`n, c`|√|√|√|√|
|`b, e`|×|√|×|√|
|`{a, b, c ...}`|×|√|×|√|

## 9.5.3 string 搜索操作

下列搜索操作都返回一个 `string::size_type` 值，表示匹配发生位置的下标。
如果搜索失败，则返回一个名为 `string::npos` 的 static 成员（见 [7.6 节](../../Chapter7_类/note/note_7.6.md)）。  
标准库将 `npos` 定义为一个 `const string::size_type` 类型，其初始值为 -1 。因为 `npos` 是 `unsigned` 类型，所以 `npos` 的实际值是其可能表示的最大值。

* `s.find(args)` ：查找 s 中 args 第一次出现的位置
* `s.rfind(args)` ：查找 s 中 args 最后一次出现的位置
* `s.find_first_of(args)` ：在 s 中查找 args 中任意一个字符第一次出现的位置
* `s.find_last_of(args)` ：在 s 中查找 args 中任意一个字符最后一次出现的位置
* `s.find_first_not_of(args)` ：在 s 中查找第一个不在 args 中的字符
* `s.find_last_not_of(args)` ：在 s 中查找最后一个不在 args 中的字符

`args` 只能是以下 4 种形式之一：

1. `c, pos` ：从 s 中位置 pos 开始查找字符 c ，pos 默认为 0
2. `str, pos` ：从 s 中位置 pos 开始查找字符串 str ，pos 默认为 0
3. `cp, pos` ：从 s 中位置 pos 开始查找指针 cp 指向的以空字符结尾的 C 风格字符串，pos 默认为 0
4. `cp, pos, n` ：从 s 中位置 pos 开始查找指针 cp 指向的字符数组的前 n 个字符，pos 和 n 需要指定，无默认值

搜索操作是大小写敏感的。

```cpp
string numbers = "0123456789";
string name = "r2d2";
string dept = "03714p3";

auto pos1 = name.find_first_of(numbers); // 查找 name 中第一个数字的下标 pos1 = 1
auto pos2 = dept.find_first_not_of(numbers); // 查找 dept 中第一个不是数字的字符下标 pos2 = 5
```

使用查找起始位置 pos 参数实现搜索子字符串出现的所有位置：

```cpp
string::size_type pos = 0;

while ((pos = name.find_first_of(numbers, pos)) != string::npos) {
    // 从 0 开始找第一个数字，并将结果赋给 pos
    cout << "Found number at index: " << pos
         << " element is " << name[pos] << endl;
    ++pos; // 从下一个字符开始找
}
```

## 9.5.4 compare 函数

`s.compare(args)` 的功能与 `strcmp` 函数类似，其有 6 种不同的参数形式：

1. `str` ：比较 s 和 str
2. `pos1, n1, str` ：将 s 中从 pos1 开始的 n1 个字符与 str 进行比较
3. `pos1, n1, str, pos2, n2` ：将 s 中从 pos1 开始的 n1 个字符与 str 中从 pos2 开始的 n2 个字符进行比较
4. `cp` ：比较 s 与 cp 指向的以空字符结尾的字符数组
5. `pos1, n1, cp` ：将 s 中从 pos1 开始的 n1 个字符与 cp 指向的以空字符结尾的字符数组进行比较
6. `pos1, n1, cp, n2` ：将 s 中从 pos1 开始的 n1 个字符与指针 cp 指向的地址开始的 n2 个字符进行比较

## 9.5.5 数值转换

string 和数值之间的转换：

* `to_string(val)` ：返回数值 val 的 string 表示，val 可以是任何算术类型
* 返回 s 的起始子串（表示整数）的数值，b 表示转换所用的基数（默认值为 10 ），p 是 size_t 指针，用来保存 s 中第一个非数值字符的下标（默认为 0 ，即不保存下标）
  * `stoi(s, p, b)` ：返回 int
  * `stol(s, p, b)` ：返回 long
  * `stoul(s, p, b)` ：返回 unsigned long
  * `stoll(s, p, b)` ：返回 long long
  * `stoull(s, p, b)` ：返回 unsigned long long
* 返回 s 的起始子串（表示浮点数）的数值，p 是 size_t 指针，用来保存 s 中第一个非数值字符的下标（默认为 0 ，即不保存下标）
  * `stof(s, p)` ：返回 float
  * `stod(s, p)` ：返回 double
  * `stold(s, p)` ：返回 long double

要转换为数值的 string 中第一个非空白字符必须是数值中可能出现的字符，转换处理直至遇到不可能是数值的字符为止。

1. 符号或数字：`+-.0123456789`
2. 以 `0x` 或 `0X` 开头的十六进制数
3. 包含 `e` 或 `E` 来表示指数部分

```cpp
string s = "pi = 3.14";
d = stod(s.substr(s.find_first_of("+-.0123456789")));
// d = 3.14
// 先用 find_first_of 找到第一个数值中可能出现的字符位置
// 再用 substr 获得后面的子串
// 最后进行数值转换
```

如果 string 不能转换为一个数值，则函数会抛出 `invalid_argument` 异常。  
如果转换得到的数值无法用任何类型表示，则函数会抛出 `out_of_range` 异常。

## 练习

* [练习 9.41](../src/quiz_9.41.cpp)
* [练习 9.42](../src/quiz_9.42.md)
* [练习 9.43](../src/quiz_9.43.cpp)
* [练习 9.44](../src/quiz_9.44.cpp)
* [练习 9.45](../src/quiz_9.45.cpp)
* [练习 9.46](../src/quiz_9.46.cpp)
* [练习 9.47](../src/quiz_9.47.cpp)
* [练习 9.48](../src/quiz_9.48.md)
* [练习 9.49](../src/quiz_9.49.cpp)
* [练习 9.50](../src/quiz_9.50.cpp)
* [练习 9.51](../src/quiz_9.51.cpp)
