# 19.4 类成员指针

> 本章术语：
>
> * 成员指针（pointer to member）：可以指向类的非静态成员的指针

以 Screen 类为例：

```cpp
class Screen {
public:
    using pos = std::string::size_type;

private:
    std::string contents;
    pos cursor;
    pos height, width;

public:
    char get_cursor() const { return contents[cursor]; }
    char get() const;
    char get(pos ht, pos wd) const;
};
```

## 19.4.1 数据成员指针

成员指针的声明：

```cpp
string Screen::*pdata; // pdata 指向 Screen 对象中的 string 成员
pdata = &Screen::contents; // 指向非特定 Screen 对象的 contents 成员（此时没有指向任何数据）
```

当初始化一个成员指针或为成员指针赋值时，该指针并没有指向任何数据。只有当解引用成员指针时才提供对象的信息。（使用 `.*` 或 `->*` ）

```cpp
Screen myScreen, *pScreen = &myScreen; // 有了特定的对象

myScreen.*pdata; // 得到特定对象 myScreen 的 contents 成员
pScreen->*pdata; // 得到特定对象 myScreen 的 contents 成员
```

成员指针同样遵守访问控制规则。因此指向私有成员的成员指针只能在类内或友元内使用。

返回成员指针的成员函数：

```cpp
class Screen {
    // ...
public:
    static const std::string Screen::*data()
    {
        // 静态成员函数 data() ，返回 const std::string Screen::*
        return &Screen::contents;
    }
};

// 初始化成员指针
const std::string Screen::*p = Screen::data();
// 获得实际的成员对象
auto s = myScreen.*p;
```

## 19.4.2 成员函数指针

成员函数指针的声明：

```cpp
char (Screen::*pmf)(Screen::pos, Screen::pos) const;
pmf = &Screen::get; // 必须使用取地址运算符，不能进行函数名到函数指针的自动转换
```

指向成员函数的指针也需要指明函数的返回类型和形参列表，并且要包含 const 的限定符或引用限定符。

使用 `.*` 或 `->*` 调用成员函数：

```cpp
Screen myScreen, *pScreen = &myScreen;

(myScreen.*pmf)(0, 0);
(pScreen->*pmf)(0, 0);
// 函数调用运算符的优先级较高，所以括号必不可少
```

为成员函数指针添加变量别名：

```cpp
using Action = char (Screen::*)(Screen::pos, Screen::pos) const;
Action a = &Screen::get;

(myScreen.*a)(0, 0);
(pScreen->*a)(0, 0);
```

## 19.4.3 将成员函数用作可调用对象

使用 function 模板将成员函数指针转换为可调用对象：

```cpp
function<bool (const string &)> f = &string::empty;
// 可调用对象 f 在 const string & 对象上调用 string::empty 函数，并返回 bool
vector<string> svec;
find_if(svec.begin(), svec.end(), f); // f 使用 .* 调用 empty

function<bool (const string *)> fp = &string::empty;
// 可调用对象 f 在 const string * 对象上调用 string::empty 函数，并返回 bool
vector<string *> psvec;
find_if(psvec.begin(), psvec.end(), fp); // fp 使用 ->* 调用 empty
```

使用 mem_fn 函数将成员函数指针转换为可调用对象：

```cpp
vector<string> svec;
vector<string *> psvec;
find_if(svec.begin(), svec.end(), mem_fn(&string::empty)); // 自动使用 .* 调用 empty
find_if(psvec.begin(), psvec.end(), mem_fn(&string::empty)); // 自动使用 ->* 调用 empty
```

使用 bind 函数将成员函数指针转换为可调用对象：

```cpp
vector<string> svec;
vector<string *> psvec;
find_if(svec.begin(), svec.end(), bind(&string::empty, _1)); // 自动使用 .* 调用 empty
find_if(psvec.begin(), psvec.end(), bind(&string::empty, _1)); // 自动使用 ->* 调用 empty
```

## 练习

* [练习 19.11](../src/quiz_19.11.md)
* [练习 19.12](../src/quiz_19.12.cpp)
* [练习 19.13](../src/quiz_19.13.md)
* [练习 19.14](../src/quiz_19.14.md)
* [练习 19.15](../src/quiz_19.15.md)
* [练习 19.16](../src/quiz_19.16.md)
* [练习 19.17](../src/quiz_19.17.md)
* [练习 19.18](../src/quiz_19.18.cpp)
* [练习 19.19](../src/quiz_19.19.cpp)
