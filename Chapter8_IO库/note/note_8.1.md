# 8.1 IO 类

IO 库类型：

1. `<iostream>`：`istream`、`ostream`、`iostream` 读写流
2. `<fstream>`：`ifstream`、`ofstream`、`fstream` 读写文件
3. `<sstream>`：`istringstream`、`ostringstream`、`stringstream` 读写 string

## 8.1.1 IO 对象无拷贝或赋值

上述 IO 对象不能对他们进行赋值、拷贝。所以流类型**不能**作为形参或返回类型，要使用*流类型的引用*。传递和返回的引用不能是 const 的。

## 8.1.2 条件状态

流对象 `strm` 的状态变量：

* `strm::iostate`：下面四个标志都是 iostate 类型
* `strm::badbit`：流已崩溃时为 true（不可恢复性错误）
* `strm:failbit`：一个 IO 操作失败时为 true（可恢复性错误）
* `strm::eofbit`：到达文件结束时为 true
* `strm::goodbit`：用来指出流未处于错误状态。此值保证为 0 。

* `s.eof()` = `strm::eofbit`
* `s.fail()` = `strm:failbit` || `strm::badbit`
* `s.bad()` = `strm::badbit`
* `s.good()`：流 s 处于有效状态
* `s.clear()`：将流 s 中所有条件状态位复位，将流的状态设置为有效
* `s.clear(flags)`：将所有状态位复位
* `s.setstate(flags)`：将所有状态位设置为给定的 iostate 变量
* `s.rdstate()`：返回当前流 s 的状态

一个流一旦发生错误，其后续的 IO 操作都会失败，只有当一个流处于无错状态时，才能读写数据。

将流作为条件使用 `while (cin >> word)` 只要 badbit、failbit、eofbit 有一个为真，检测条件就为假。

`s.clear()`、`s.clear(flags)`、`s.setstate(flags)`、`s.rdstate()`用法：

```cpp
auto old_state = cin.rdstate(); // 获取当前状态
cin.clear(); // 恢复 cin 初始状态
process_input(cin); // 使用 cin
cin.setstate(old_state); // 还原 cin 的状态

// 只复位 failbit 和 badbit，其他标志位不变
cin.clear(cin.rdstate() & ~cin.failbit & ~cin.badbit);
```

## 8.1.3 管理输出缓冲

刷新输出缓冲区的情况：

1. `main` 函数执行 `return` 语句时刷新缓冲
2. 缓冲区满时刷新缓冲
3. 使用 endl 、 ends 、 flush 刷新缓冲
4. 使用 unitbuf 操纵符控制刷新缓冲
5. 当读/写相关联的流时，关联到的流的缓冲区会被刷新。

```cpp
cout << "hi!" << endl;  // endl 输出一个换行符，然后刷新缓冲区
cout << "hi!" << ends;  // ends 输出一个空字符，然后刷新缓冲区
cout << "hi!" << flush; // flush 刷新缓冲区，但不输出任何字符
```

可以使用 unitbuf 操纵符实现每次输出都刷新缓冲区；使用 nounitbuf 恢复默认刷新机制。

```cpp
cout << unitbuf;     // 此后的所有输出操作执行完都会立即刷新缓冲区
cout << "Something"; // 输出完 Something 后立即刷新缓冲区
cout << nounitbuf;   // 回到正常的缓冲方式
```

关联输入和输出流

```cpp
cin.tie(&cout); // 标准库默认将 cin 和 cerr 与 cout 关联
ostream *current_tie = cin.tie(); // 无参数时返回当前与 cin 关联的流的指针
ostream *old_tie = cin.tie(nullptr); // cin 不再与任何流关联，old_tie 为 cin 之前关联的流的指针，即指向 cout 的指针
```

标准库中，读 cin 和写 cerr 都会刷新其关联的 cout 的缓冲区。

*程序崩溃/异常终止时，输出缓冲区不会被刷新。已崩溃的程序没有输出数据，可能是因为数据在输出缓冲区中而未刷新。*

## 练习

* [练习 8.1](../src/quiz_8.1.cpp)
* [练习 8.2](../src/quiz_8.2.cpp)
* [练习 8.3](../src/quiz_8.3.md)
