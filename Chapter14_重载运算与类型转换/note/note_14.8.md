# 14.8 函数调用运算符

> 本章术语：
>
> * 函数对象（function object）：定义了调用运算符的类的对象
> * 调用形式（call signature）：指明了调用返回的类型以及传递给调用的实参类型，如 `int(int, int)` 表示接受两个 int ，返回一个 int
> * 函数表（function table）：用于储存指向相同调用形式的对象的“指针”

函数调用运算符必须是成员函数。

一个类可以定义多个不同版本的调用运算符，相互之间的区别在于参数数量或参数类型。

定义了函数调用运算符的类的对象是一种含有状态的函数对象：

```cpp
class PrintString
{
private:
    ostream &os; // 保存用于输出的流
    char sep;    // 用于分隔字符串的字符

public:
    // 构造函数
    PrintString(ostream &o = cout, char c = ' ') : os(o), sep(c) {} // 默认使用标准输出流，使用空格分隔字符串

    // 函数调用运算符
    void operator()(const string &s) const
    {
        os << s << sep;
    }
};
```

函数对象往往作为泛型算法的实参：

```cpp
for_each(svec.begin(), svec.end(), PrintString(cerr, '\n'));
// 将 svec 中的每个 string 打印到 cerr 中，并以换行符分隔
```

## 14.8.1 lambda 是函数对象

当我们定义了一个 lambda 后，编译器会将该表达式翻译成一个未命名类的未命名对象。该类中含有一个重载的函数调用运算符。

```cpp
[](const string &a, const string &b) { return a.size() < b.size(); }

// 上述 lambda 表达式会被编译器翻译成下面的等价形式
class ShorterString
{
public:
    bool operator()(const string &s1, const string s2) const
    {
        return s1.size() < s2.size();
    }
};
```

当 lambda **引用捕获**变量时，编译器会直接使用变量的引用，而**不会**在翻译的类中创建对应的数据成员。  
当 lambda **值捕获**变量时，编译器**会**在翻译的类中创建对应的数据成员，同时创建构造函数，使用捕获的变量的值初始化数据成员。

```cpp
[sz](const string &a) { return a.size() >= sz; } // sz 是值捕获变量

// 上述 lambda 表达式会被编译器翻译成下面的等价形式
class SizeComp
{
private:
    size_t sz; // 储存值捕获的变量

public:
    // 初始化数据成员的构造函数
    SizeComp(size_t n) : sz(n) {} // 使用捕获的变量初始化对应的数据成员

    bool operator()(const string &s) const
    {
        return s.size() >= sz;
    }
};
```

lambda 表达式产生的类不含默认构造函数、赋值运算符及默认析构函数；  
lambda 表达式产生的类是否含有默认的拷贝/移动构造函数通常要视捕获的数据成员类型而定。

## 14.8.2 标准库定义的函数对象

|算术|关系|逻辑|
|:-|:-|:-|
|plus\<Type>|equal_to\<Type>|logical_and\<Type>|
|minus\<Type>|not_equal_to\<Type>|logical_or\<Type>|
|multiplies\<Type>|greater\<Type>|logical_not\<Type>|
|divides\<Type>|greater_equal\<Type>||
|modulus\<Type>|less\<Type>||
|negate\<Type>|less_equal\<Type>||

例：

```cpp
plus<Sales_data> plus_obj; // plus_obj 对象调用 Sales_data 的 operator+ 运算符
Sales_data s1, s2;

Sales_data sum = plus_obj(s1, s2); // 调用 Sales_data 的 operator+ 对 s1 和 s2 求和
```

在泛型算法中使用标准库函数对象作为谓词：

```cpp
sort(svec.begin(), svec.end(), greater<string>());
// 生成一个 greater<string> 类的临时对象，使用 > 运算符而非 < 对 svec 进行排序

vector<string *> pointer_vec;
sort(pointer_vec.begin(), pointer_vec.end(), less<string *>());
// 对指针的内存地址进行排序
// 指向不同 string 的元素的指针不能进行比较，会产生未定义的行为
[](string *a, string *b) { return a < b; } // 该 lambda 不能用于比较地址大小，会产生未定义的行为
```

## 14.8.3 可调用对象与 function

可调用的对象：函数、函数指针、lambda 表达式、bind 创建的对象、重载了函数调用运算符的类

可调用对象的类型：lambda 有它自己唯一的未命名的类类型；函数和函数指针的类型由返回值类型和实参类型决定

不同类型的可调用对象可能具有相同的调用形式：

```cpp
// 普通函数
int add(int i, int j) { return i + j; }

// lambda 表达式
auto mod = [](int i, int j) { return i % j; };

// 函数对象类
class divide {
public:
    int operator()(int i, int j) {
        return i / j;
    }
};
```

上述三个可调用对象的类型不同，但是调用形式相同，都是 `int(int, int)` 。

### 可以使用标准库 function 类型，将调用形式相同但类型不同的调用对象抽象成同一类

function 的操作：

* `function<T> f;` ：f 是一个用来储存可调用对象的空 function ，T 是可调用对象的调用形式
* `function<T> f(nullptr);` ：显式地构造一个空 function
* `function<T> f(obj);` ：f 储存可调用对象 obj 的副本
* `f` ：当 f 用于条件判断时，f 保存可调用对象时为 true ，f 为空时为 false
* `f(args)` ：使用参数 args 调用 f 中存储的可调用对象
* `function<T>` 中的成员类型：
  * `result_type` ：可调用对象的返回值类型
  * `argument_type` ：当调用形式只有一个实参时，表示该实参的类型
  * `first_argument_type` 、`second_argument_type` ：当调用形式有两个实参时，分别表示两个实参的类型

function 使用示例：

```cpp
// 定义
function<int(int, int)> f1 = add; // 使用函数指针
function<int(int, int)> f2 = divide(); // 使用函数对象类实例化的对象
function<int(int, int)> f3 = [](int i, int j) { return i * j; }; // 使用 lambda 表达式

// 调用
cout << f1(4, 2) << endl; // 打印 6
cout << f2(4, 2) << endl; // 打印 2
cout << f3(4, 2) << endl; // 打印 8

// 创建函数表
map<string, function<int(int, int)>> binops = {
    {"+", add},                                // 函数指针
    {"-", std::minus<int>()},                  // 标准库的函数对象
    {"/", divide()},                           // 自定义的函数对象
    {"*", [](int i, int j) { return i * j; }}, // 未命名的 lambda 对象
    {"%", mod}                                 // 已命名的 lambda 对象
};

// 使用函数表
binops["+"](10, 5); // 返回 15
binops["-"](10, 5); // 返回 5
binops["*"](10, 5); // 返回 50
binops["/"](10, 5); // 返回 2
binops["%"](10, 5); // 返回 0
```

不能直接将重载的函数存入 function 类型的对象中，需要通过储存函数指针或 lambda 表达式来消除二义性：

```cpp
// 重载的 add 函数
int add(int i, int j)
{
    return i + j;
}
Sales_data add(const Sales_data &i, const Sales_data &j)
{
    Sales_data sum = i;
    sum.units_sold += j.units_sold;
    sum.revenue += j.revenue;
    return sum;
}

binops.insert({"+", add}); // 错误：出现二义性，add 函数有两个版本

int (*fp)(int, int) = add;
binops.insert({"+", fp}); // 正确：通过函数指针 fp 指明正确的 add 版本

binops.insert({"+", [](int a, int b){return add(a, b);}}); // 正确：通过 lambda 表达式指明正确的 add 版本
```

## 练习

* [练习 14.33](../src/quiz_14.33.md)
* [练习 14.34](../src/quiz_14.34.cpp)
* [练习 14.35](../src/quiz_14.35.hpp)
* [练习 14.36](../src/quiz_14.36.cpp)
* [练习 14.37](../src/quiz_14.37.cpp)
* [练习 14.38](../src/quiz_14.38.cpp)
* [练习 14.39](../src/quiz_14.39.cpp)
* [练习 14.40](../src/quiz_14.40.cpp)
* [练习 14.41](../src/quiz_14.41.md)
* [练习 14.42](../src/quiz_14.42.md)
* [练习 14.43](../src/quiz_14.43.cpp)
* [练习 14.44](../src/quiz_14.44.cpp)
