# 8.3 string 流

头文件 `<sstream>` 中定义的三种读写 string 的类型：

* `istringstream` ：从 string 中读取数据
* `ostringstream` ：向 string 写入数据
* `stringstream` ：读写 string

上述类型（统一记为 sstream ）支持的操作：

* `sstream strm;` ：定义一个未绑定的 stringstream 对象
* `sstream strm(s);` ：定义一个 stringstream 对象，保存 string s 的一个拷贝
* 继承 iostream 的操作
* `strm.str()` ：返回 strm 保存的 string 的拷贝
* `strm.str(s)` ：将 string s 拷贝到 strm 中，返回 void

## 8.3.1 使用 istringstream

当处理一整行文本中的每个单词时，通常可以使用 istringstream。

```cpp
// 使用示例
string line, world;
while (getline(cin, line)) // 从标准输入中获得一行内容
{
    istringstream record(line); // 将一行文本 line 拷贝给 string 流 record
    while (record >> word) // 处理 record 中的每一个单词
    {
        处理 word;
    }
}
```

*如果 record 定义在 while 循环外，需要注意使用 `record.clear();` 将流的状态置为有效。*

## 8.3.2 使用 ostringstream

可以使用 ostringstream 逐步构造输出内容，最后一起打印。

```cpp
// 使用示例
ostringstream ostrm;
ostrm << "Something.";
cout << ostrm.str() << endl;
```

## 练习

* [练习 8.9](../src/quiz_8.9.cpp)
* [练习 8.10](../src/quiz_8.10.cpp)
* [练习 8.11](../src/quiz_8.11.cpp)
* [练习 8.12](../src/quiz_8.12.md)
* [练习 8.13](../src/quiz_8.13.cpp)
* [练习 8.14](../src/quiz_8.14.md)
