# 8.2 文件输入输出

头文件 `<fstream>` 中定义的三种文件 IO 类型：

* `ifstream` ：从给定文件读取数据
* `ofstream` ：向给定文件写入数据
* `fstream` ：读写给定文件

上述类型（统一记为 fstream ）支持的操作：

* `fstream fstrm;` ：创建一个未绑定文件的文件流 fstrm
* `fstream fstrm(s);` ：创建一个绑定文件名 s 的文件流 fstrm
* `fstream fstrm(s, mode);` ：用指定 mode 打开文件 s
* 与 `cin` 、 `cout` 相同用法的 `<<` 、 `>>` 、 `getline`
* `fstrm.open(s)` ：打开名为 s 的文件，返回 void
* `fstrm.close()` ：关闭与 fstrm 绑定的文件，返回 void
* `fstrm.is_open()` ：当与 fstrm 绑定的文件成功打开并尚未关闭时，返回 true

## 8.2.1 使用文件流对象

*基类型形参可以传入继承类型实参。接受 iostream 类型的引用或指针同样接受 fstream 和 sstream 类型。*

如果 `fstrm.open(s)` 调用失败，则 `fstrm::failbit` 为 true 、 `if (fstrm)` 为 false

对已经绑定并打开文件的文件流 `fstrm` 再执行 `open` 会导致 `fstrm::failbit` 为 true

创建的 `fstrm` 对象在离开其作用域时，会自动调用 `close` 函数。

## 8.2.2 文件模式

`fstream fstrm(s, mode);` 中 mode 可取的值：

* `in` ：以读方式打开
* `out` ：以写方式打开
* `app` ：每次写操作前都定位到文件末尾
* `ate` ：打开文件后立即定位到文件末尾
* `trunc` ：截断文件（即覆盖文件原有内容）
* `binary` ：以二进制方式进行 IO

限制：

* 只有 ofstream 对象和 fstream 对象可以设定 out 模式
* 只有 ifstream 对象和 fstream 对象可以设定 in 模式
* 只有设定 out 模式的前提下才能设定 turnc 模式
* 只要没设定 turnc 模式，就可以设定 app 模式；app 模式总是 out 模式
* 默认情况下，不设定 turnc 模式的 out 模式也会截断文件；须设定 app 模式将内容追加到文件末尾
* ate 和 binary 模式可用于任何类型的文件流对象，且可以与其他任何文件模式组合使用

默认文件模式：

* ifstream 默认以 in 模式打开
* ofstream 默认以 out 模式打开
* fstream 默认以 in 和 out 模式打开

*以 out 模式打开的文件原有内容会被丢弃。以 app 模式打开文件可以将内容追加到文件末尾。*

```cpp
// 截断文件
ofstream out1("file1");
ofstream out2("file1", ofstream::out);
ofstream out3("file1", ofstream::out | ofstream::turnc);

// 追加内容
ofstream app1("file2", ofstream::app);
ofstream app2("file2", ofstream::out | ofstream::app);
```

## 练习

* [练习 8.4](../src/quiz_8.4.cpp)
* [练习 8.5](../src/quiz_8.5.cpp)
* [练习 8.6](../src/quiz_8.6.cpp)
* [练习 8.7](../src/quiz_8.7.cpp)
* [练习 8.8](../src/quiz_8.8.cpp)
