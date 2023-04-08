# 10.3 定制操作

> 本章术语：
>  
> * 谓词（predicate）：一个可调用的表达式，返回结果是一个能用作条件的值
> * 一元谓词（unary predicate）：只接受一个参数
> * 二元谓词（binary predicate）：有两个参数
> * 可调用对象（callable object）：能够对其使用调用运算符“()”的对象
> * lambda 表达式（lambda expression）：表示一个可调用的单元代码，可以将其理解为一个未命名的内联函数

重载算法比较的默认操作。

## 10.3.1 向算法传递函数

sort 的重载版本接受第三个参数，该参数是一个谓词。

stable_sort 是稳定排序算法，维持想等元素的原有顺序。

## 10.3.2 lambda 表达式

可调用对象：

* 函数和函数指针
* 重载了函数调用运算符的类
* lambda 表达式

### lambda 表达式的形式

`[capture list] (parameter list) -> return type {function body}`

* `capture list`：捕获列表，是一个 lambda 所在函数中定义的局部变量的列表（以逗号分隔）
* `return type`：返回类型（使用尾置返回 [6.3.3 小节](../../Chapter6_%E5%87%BD%E6%95%B0/note/note_6.3.md)）
* `parameter list`：参数列表
* `function body`：函数体

### lambda 表达式可以忽略参数列表和返回类型，但是必须包含捕获列表和函数体

`auto f = [] {return 42;};`

### lambda 表达式的调用与普通函数相同

`cout << f() << endl;`

### lambda 表达式的返回类型（省略返回类型的情况下）

* 只含有一条 return 语句：根据 return 语句推断
* 除了 return 语句之外还有其他内容：返回 void

### 向 lambda 传递参数

lambda 不能有默认参数；一个 lambda 调用的实参数目永远与形参数目相等。

一个 lambda 只有在其捕获列表中捕获一个它所在函数中的局部变量，才能在函数体中使用该变量。

一个 lambda 可以直接使用定义在当前函数之外的名字（如全局变量），对于定义在当前函数内的局部变量，必须加入到捕获列表中，才能在函数体中使用。

*捕获列表只用于局部非 static 变量，lambda 可以直接使用局部 static 变量和在它所在函数之外声明的名字。*

### 示例

```cpp
vector<string>::size_type sz = 5;
auto wc = find_if(words.begin(), words.end(), 
    [sz](const string &s) {return s.size() >= sz;});
// wc 是指向第一个长度大于等于 5 的 string 的迭代器
```

### for_each 算法

for_each 算法接受一个可调用对象，对输入范围内的每一个元素都调用此对象。

```cpp
// 使用 for_each 算法进行遍历输出
for_each(words.begin(), words.end(),
    [](const string &s) {cout << s << " ";});
cout << endl;
```

## 10.3.3 lambda 捕获和返回

一个 lambda 相当于一个类。捕获列表中的变量相当于类中的成员变量。  
lambda 的数据成员在 lambda 对象创建时被初始化（与普通类的数据成员类似）。

|lambda 捕获列表|含义|
|:-:|:-|
|`[]`|空捕获列表，lambda 函数体中不能使用所在函数中的变量|
|`[names]`|names 是逗号分隔的名字列表，正常情况下值捕获，名字前有&为引用捕获|
|`[&]`|隐式捕获中的引用捕获|
|`[=]`|隐式捕获中的值捕获|
|`[&, identifier_list]`|identifier_list 中的名字都采用值捕获，函数体中的其他名字采用引用捕获|
|`[=, identifier_list]`|identifier_list 中的名字都采用引用捕获，函数体中的其他名字采用值捕获|

### 值捕获

* 与传值参数类似，采用值捕获的前提是变量可以拷贝
* 与传值参数不同，被捕获的变量的值是在 lambda 创建时拷贝，而非调用时拷贝

```cpp
void fun1()
{
    size_t v1 = 42; // 局部变量
    auto f = [v1] {return v1;}; // 已经将 v1 的值拷贝到 lambda 中（创建时拷贝）
    v1 = 0; // 对 lambda 的返回值没有影响
    auto j = f(); // j 的值为 42 （而非调用时拷贝）
}
```

### 引用捕获

当以引用方式捕获一个变量时，必须保证在 lambda 执行时变量是存在的。  
lambda 可以作为函数的返回值，此时 lambda 不能包含函数中局部变量的引用。

```cpp
void fun2()
{
    size_t v1 = 42; // 局部变量
    auto g = [&v1] {return v1;}; // 使用引用捕获，v1 的值始终与局部变量的值同步
    v1 = 0;
    auto j = g(); // j 的值为 0
}
```

*注意：能使用值捕获就尽量避免使用引用捕获/指针捕获，避免 lambda 的值被意外修改。尽量减少捕获的数据量。*

### 隐式捕获

让编译器推断 lambda 函数体中哪些变量需要捕获。  
`[=]` 表示隐式值捕获；`[&]` 表示隐式引用捕获。

### 混合捕获

同时使用隐式捕获和显式捕获，隐式捕获和显式捕获的捕获方式**必须不同**。  
`[=, identifier_list]` 表示隐式捕获使用值捕获，显式捕获使用引用捕获。  
`[&, identifier_list]` 表示隐式捕获使用引用捕获，显式捕获使用值捕获。

### 改变捕获列表中变量的值（可变 lambda）

默认情况下，lambda 不能改变值捕获的变量。如果要改变，应该添加 mutable 关键字：

```cpp
void fun3()
{
    size_t v1 = 42; // 局部变量
    auto f = [v1] () mutable {return ++v1;}; // 函数体内 v1 可以改变
    v1 = 0;
    auto j = f(); // j 的值为 43
}
```

引用捕获的变量能否改变，取决于该引用指向的是 const 类型还是非 const 类型：

```cpp
void fun4()
{
    size_t v1 = 42; // 非 const 类型
    auto g = [&v1] {return ++v1;}; // 如果 v1 是 const size_t 型，就不能改变 v1 的值
    v1 = 0;
    auto j = g(); // j 的值为 1
}
```

### 指定 lambda 的返回类型

transform 算法接受 4 个参数（3 个迭代器和 1 个可调用对象）。前两个迭代器表示输入范围，第三个迭代器表示输出位置。算法对输入范围内的每个元素调用可调用对象，并将结果写入输出位置。

```cpp
// 函数体中只有一条 return 语句时，可以不指定返回类型
transform(vi.begin(), vi.end(), vi.begin(),
    [](int i) {return (i < 0) ? -i : i;});

// 其他情况都必须显式指定返回类型，否则默认返回 void
transform(vi.begin(), vi.end(), vi.begin(),
    [](int i) -> int
    {if (i < 0) return -i; else return i;});
```

## 10.3.4 参数绑定

使用标准库 `functional` 中的 `bind` 函数可以对可调用对象的参数进行绑定，生成新的可调用对象。

```cpp
auto newCallable = bind(callable, arg_list);
```

* `newCallable`：新生成的可调用对象
* `arg_list`：一个逗号分隔的参数列表（`_1` 为 newCallable 的第一个参数，`_2` 为第二个参数，以此类推）

当调用 newCallable 时，会以 arg_list 为参数调用 callable 。其中 `_1` 、`_2` 等都是 newCallable 的参数。

```cpp
string::size_type sz = 6;
// 使用 lambda 的 find_if
auto wc = find_if(words.begin(), words.end(),
    [sz](const string &a) {return a.size() >= sz;});

// 使用 check_size 并用 bind 进行参数绑定的 find_if
bool check_size(const string &s, string::size_type sz)
{
    return s.size() >= sz;
}
auto wc = find_if(words.begin(), words.end(),
    bind(check_size, _1, sz));
```

### 使用 bind 改变参数顺序

```cpp
auto g = bind(f, a, b, _2, c, _1);
```

`g(m, n)` 等价于 `f(a, b, n, c, m)` 。

### 使用 bind 绑定引用

```cpp
auto g = bind(f, a, ref(b), _2, cref(c), _1);
// 将变量 a 的拷贝传递给函数 f （相当于 lambda 的值捕获）
// 将指向变量 b 的引用传递给函数 f （相当于 lambda 的引用捕获）
// 传递给函数 f 的 c 是 const 引用
```

`ref` 和 `cref` 定义在头文件 `functional` 中。

### placeholders 名字

占位符 `_1` 、`_2` …… `_n` 都定义在 `placeholders` 命名空间中，这个命名空间定义在 `std` 命名空间中。

为了让 `_1` 的使用（`using std::placeholders::_1;`）更加简洁，可以提前声明命名空间：`using namespace placeholders;`

`placeholders` 命名空间定义在 `functional` 头文件中。

## 练习

* [练习 10.11](../src/quiz_10.11.cpp)
* [练习 10.12](../src/quiz_10.12.cpp)
* [练习 10.13](../src/quiz_10.13.cpp)
* [练习 10.14](../src/quiz_10.14.cpp)
* [练习 10.15](../src/quiz_10.15.cpp)
* [练习 10.16](../src/quiz_10.16.cpp)
* [练习 10.17](../src/quiz_10.17.cpp)
* [练习 10.18](../src/quiz_10.18.cpp)
* [练习 10.19](../src/quiz_10.19.cpp)
* [练习 10.20](../src/quiz_10.20.cpp)
* [练习 10.21](../src/quiz_10.21.cpp)
* [练习 10.22](../src/quiz_10.22.cpp)
* [练习 10.23](../src/quiz_10.23.md)
* [练习 10.24](../src/quiz_10.24.cpp)
* [练习 10.25](../src/quiz_10.25.cpp)
