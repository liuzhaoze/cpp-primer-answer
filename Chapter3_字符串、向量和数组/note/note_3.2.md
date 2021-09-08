## 3.2 标准库类型 string

> 本章术语：
> * 拷贝初始化（copy initialization）：使用等号初始化一个变量。
> * 直接初始化（direct initialization）：不使用等号，使用小括号。
> * 范围 for 语句（range for）
> * 下标运算符（`[]`）
> * 逻辑与运算符（`&&`）


### 3.2.1 定义和初始化 string 对象
```c
string s1;            // 默认初始化， s1 是空字符串
string s2(s1);        // s2 是 s1 的副本
string s2 = s1;       // s2 是 s1 的副本
string s3("value");   // s3 是字面值"value"的副本（除'\0'外）
string s3 = "value";  // s3 是字面值"value"的副本（除'\0'外）
string s4(10, 'c');   // 把 s4 初始化为由连续 10 个字符 c 组成的串
```

### 3.2.2 string 对象上的操作
```c
os << s
is >> s
getline(is, s)
s.empty()
s.size()
s[n]
s1 + s2
s1 = s2
s1 == s2
s1 != s2
<, <=, >, >=
```

读取 string ： string 对象会自动忽略开头的空白，并从第一个真正的字符开始读起，直到遇见下一处空白为止。

```c
// 读取未知数量的 string 对象
while(cin >> word)
    cout << word << endl;

while(getline(cin, line))
    cout << line << endl;
```

getline 只要一遇到换行符就结束读取操作并返回结果。
读取时包括换行符，返回的结果不包括换行符。

`s.size()` 返回一个 `string::size_type` 类型的值。
它是无符号类型的值。

**表达式中避免带符号数和无符号数的混用。**
如果一条表达式中已经有 `size()` 函数，则不要使用 `int` 等带符号类型。

string 对象的比较：字符相同短的小，字符不同按 ASCII 比较第一对不同的字符。

当把 string 对象和字符字面值及字符串字面值混在一条语句中使用时，必须确保每个加法运算符的两侧的运算对象至少有一个是 string 。

### 3.2.3 处理 string 对象中的字符
cctype 头文件中的函数
```c
isalnum(c)
isalpha(c)
iscntrl(c)
isdigit(c)
isgraph(c)
islower(c)
isprint(c)
ispunct(c)
isspace(c)
isupper(c)
isxdigit(c)
tolower(c)
toupper(c)
```

使用 C++ 版本的 C 标准库头文件： `name.h` -> `cname` 。  
在名为 `cname` 的头文件中定义的名字从属于命名空间 std ，
而定义在名为 `.h` 的头文件中的则不然。

```c
// 范围 for 语句
for (declaration : expression)
    statement

string str("some string");
for (auto c : str)
    // 对于字符串 str 中的每一个字符 c ……
    cout << c << endl;
```

如果想要改变 string 对象中字符的值，必须把循环变量定义成引用类型。

访问 string 对象中的单个字符有两种方式：一种是使用下标，另外一种是使用迭代器。

string 对象的下标必须大于等于 0 而小于 `s.size()` 。

在访问指定字符之前，首先检查 s 是否为空： `!s.empty()` 。

C++ 语言规定只有当左侧运算对象为真时才会检查右侧运算对象的情况。  
`index != s.size() && !isspace(s[index])` 两个条件位置不能互换。

### 练习
* [练习 3.2](../src/quiz_3.2.cpp)
* [练习 3.3](../src/quiz_3.3.md)
* [练习 3.4](../src/quiz_3.4.cpp)
* [练习 3.5](../src/quiz_3.5.cpp)
* [练习 3.6](../src/quiz_3.6.cpp)
* [练习 3.7](../src/quiz_3.7.cpp)
* [练习 3.8](../src/quiz_3.8.cpp)
* [练习 3.9](../src/quiz_3.9.cpp)
* [练习 3.10](../src/quiz_3.10.cpp)
