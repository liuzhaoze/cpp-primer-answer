# 17.5 IO 库再探

> 本章术语：
>
> * 操纵符（manipulator）：修改流的格式状态（整型数的进制、浮点数的精度、一个输出元素的宽度）
> * 格式化 IO （formatted IO）：使用输入或输出运算符根据读取或写入的数据类型来格式化它们
> * 未格式化 IO （unformatted IO）：允许将一个流当做一个无解释的字节序列来处理

## 17.5.1 格式化输入与输出

大多数操纵符的使用都是成对的：一个操纵符用来将格式状态设置为一个新值，而另一个用来将其复原，恢复为正常的默认格式。

*当操纵符改变流的格式状态时，通常改变后的状态对后续 IO 都生效。*

控制布尔值的格式：

```cpp
cout << true << " " << false << endl; // 输出 1 0
cout << boolalpha << true << " " << false << noboolalpha << endl; // 输出 true false
```

指定整型值的进制：

```cpp
cout << showbase; // 在输出结果中显示进制
cout << uppercase; // 用大写字母表示十六进制
cout << "default: "        << 20 << " " << 1024 << endl;
cout << "octal: "   << oct << 20 << " " << 1024 << endl;
cout << "hex: "     << hex << 20 << " " << 1024 << endl;
cout << "decimal: " << dec << 20 << " " << 1024 << endl;
cout << noshowbase; // 恢复状态
cout << nouppercase;
```

*接受参数的操纵符都定义在头文件 `<iomanip>` 中。*

指定浮点值的精度：

```cpp
cout.precision();   // 返回当前精度（有效数字位数）
cout.precision(12); // 设置打印精度

cout << setprecision(3); // 在输出流中设置打印精度
```

定义在 `<iostream>` 中的操纵符：

* `boolalpha` ：将 true 和 false 输出为字符串
* `noboolalpha` ：将 true 和 false 输出为 1 和 0 （默认）
* `showbase` ：对整型值输出表示进制的前缀
* `noshowbase` ：不生成表示进制的前缀（默认）
* `showpoint` ：对浮点值总是显示小数点
* `noshowpoint` ：只有当浮点值包含小数部分时才显示小数点（默认）
* `showpos` ：对非负数显示 +
* `noshowpos` ：对非负数不显示 + （默认）
* `uppercase` ：在十六进制值中打印 0X ，在科学计数法中打印 E
* `nouppercase` ：在十六进制值中打印 0x ，在科学计数法中打印 e （默认）
* `dec` ：整型值显示为十进制（默认）
* `hex` ：整型值显示为十六进制
* `oct` ：整型值显示为八进制
* `left` ：在值的右侧添加填充字符
* `right` ：在值的左侧添加填充字符
* `internal` ：在符号和值之间添加填充字符
* `fixed` ：浮点值显示为定点十进制
* `scientific` ：浮点值显示为科学计数法
* `hexfloat` ：浮点值显示为十六进制
* `defaultfloat` ：重置浮点数格式为十进制
* `unitbuf` ：每次输出操作后都刷新缓冲区
* `nounitbuf` ：恢复正常的缓冲区刷新方式（默认）
* `skipws` ：输入运算符跳过空白符（默认）
* `noskipws` ：输入运算符不跳过空白符
* `flush` ：刷新 ostream 缓冲区
* `ends` ：插入空字符，然后刷新 ostream 缓冲区
* `endl` ：插入换行，然后刷新 ostream 缓冲区

控制输出格式的对齐：

* `setw(i)` ：指定**下一个**字符串或数字应该占据的最小空间为 i 个字符
* `left` / `right` ：指定字符串在空间中是左对齐还是右对齐（默认右对齐）
* `internal` ：当数字是负数时，令负号左对齐，数值右对齐，中间用空格填充
* `setfill(c)` ：使用字符 c 代替空格来填充空白

定义在 `<iomanip>` 中的操纵符：

* `setfill(ch)` ：用 ch 填充空白
* `setprecision(n)` ：将浮点精度设置为 n
* `setw(w)` ：读或写值的宽度为 w 个字符
* `setbase(b)` ：将整数输出为 b 进制

控制输入格式：

```cpp
/**
 * 输入序列：
 * a<space>b<tab>c<\n>
 * d
 */
char ch;
while (cin >> ch)
    cout << ch;
// 执行 4 次，分别读入/输出 abcd

char ch;
while (cin >> noskipws >> ch)
    cout << ch;
cin >> skipws; // 恢复输入流状态
// 执行 7 次，读入/输出包括空白字符在内的所有字符
```

空白字符包括：空格符、制表符、换行符、换纸符、回车符。

## 17.5.2 未格式化的输入/输出操作

单字节低层 IO 操作：

* `is.get(ch)` ：从 istream is 读取下一个字节存入字符 ch 中，返回 is
* `os.put(ch)` ：将字符 ch 输出到 ostream os ，返回 os
* `is.get()` ：将 is 的下一个字节作为 int 返回
* `is.peek()` ：将下一个字节作为 int 返回，但不从流中删除它
* `is.unget()` ：将 is 向后移动一个字节，返回 is （即退回一个已读取的字节放回流中）
* `is.putback(ch)` ：将字符 ch 放回 is ，返回 is （即退回一个已读取的字节放回流中，ch 必须与最近读取的字节相同）

```cpp
// 与 noskipws 完全相同
char ch;
while (cin.get(ch))
    cout.put(ch);
```

一般情况下，在读取下一个值之前，标准库保证我们最多可以退回一个值；标准库不保证在中间不进行读取操作的情况下能连续调用 putback 和 unget 。

get 和 peek 先将字符转换为 unsigned char ，然后再提升为 int 。

```cpp
int ch;
while ((ch = cin.get()) != EOF)
    cout.put(ch);
// EOF 定义在 <cstdio> 中
```

多字节低层 IO 操作：

* `is.get(sink, size, delim)` ：从 is 中读取最多 size 个字节，并保存在字符数组中，字符数组的起始地址由 sink 给出。读取过程直至遇到字符 delim 或读取了 size 个字节或遇到文件尾时停止。如果遇到了 delim ，则将其留在输入流中，不读取出来存入 sink
* `is.getline(sink, size, delim)` ：与接受三个参数的 get 版本类似，但会读取并丢弃 delim
* `is.read(sink, size)` ：读取最多 size 个字节，存入字符数组 sink 中，返回 is
* `is.gcount()` ：返回上一个未格式化读取操作从 is 读取的字节数
* `os.write(source, size)` ：将字符数组 source 中的 size 个字节写入 os ，返回 os
* `is.ignore(size, delim)` ：读取并忽略最多 size 个字符，包括 delim 。与其他未格式化函数不同，ignore 有默认参数：size 默认为 1 ，delim 默认为文件尾 EOF

get 和 getline 都会一直读取数据存入 sink ，直到下面条件之一发生：

* 已读取了 size - 1 个字符
* 遇到了文件尾
* 遇到了分隔符 delim

get 将分隔符留作 istream 中的下一个字符，getline 读取并丢弃分隔符。两者都不会将分隔符保存在 sink 中。

应该在任何后续未格式化输入操作之前调用 gcount 来确定最后一个未格式化输入操作读取了多少个字符。  
将字符退回流的单字符操作也属于未格式化输入操作。如果在调用 gcount 之前调用了 peek 、unget 或 putback ，则 gcount 的返回值为 0 。

## 17.5.3 流随机访问

istream 和 ostream 类型通常不支持随机访问，本节只适用于 fstream 和 sstream 。

IO 类型维护一个**标记**来确定下一个读写操作要在哪里进行。标记只有一个，不存在“读标记”或“写标记”。

seek 和 tell 函数（g 版本用于输入，意为 get ；p 版本用于输出，意为 put）：

* `tellg()` / `tellp()` ：返回输入流/输出流中标记的当前位置，返回 pos_type 值
* `seekg(pos)` / `seekp(pos)` ：在输入流或输出流中将标记重定位到给定的绝对地址；pos 通常是前一个 tellg 或 tellp 返回的值
* `seekg(off, from)` / `seekp(off, from)` ：在输入流或输出流中将标记定位到 from 之前或之后 off 个字符，from 的取值如下：
  * `beg` 偏移量相对于流开始位置
  * `cur` 偏移量相对于流当前位置
  * `end` 偏移量相对于流结尾位置
* `pos` 的类型是 `pos_type` ，是无符号数 ；`off` 的类型是 `off_type` ，是带符号数

tell 函数通常用来记住一个位置，以便稍后再定位回来。

计算偏移量时，必须包含每行末尾不可见的换行符。

## 练习

* [练习 17.34](../src/quiz_17.34.cpp)
* [练习 17.35](../src/quiz_17.35.cpp)
* [练习 17.36](../src/quiz_17.36.cpp)
* [练习 17.37](../src/quiz_17.37.cpp)
* [练习 17.38](../src/quiz_17.38.cpp)
* [练习 17.39](../src/quiz_17.39.cpp)
