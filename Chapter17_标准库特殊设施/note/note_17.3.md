# 17.3 正则表达式

> 本章术语：
>
> * 正则表达式（regular expression）

正则表达式库（RE库）定义在头文件 `<regex>` 中。

正则表达式库组件：

* `regex` ：表示有一个正则表达式的类
* `regex_match` ：将一个字符序列与一个正则表达式匹配
* `regex_search` ：寻找第一个与正则表达式匹配的子序列（只要出现一个匹配子序列就会停止查找）
* `regex_replace` ：使用给定格式替换一个正则表达式
* `sregex_iterator` ：迭代器适配器，调用 regex_search 来遍历一个 string 中所有匹配的子串
* `smatch` ：容器类，保存在 string 中搜索的结果
* `ssub_match` ：string 中匹配的子表达式的结果

`regex_match` 和 `regex_search` 的参数（两个函数都返回 bool 值，表示是否找到匹配）：

* `(seq, m, r, mft)` / `(seq, r, mft)` ：在字符序列 `seq` 中查找 regex 对象 `r` 中的正则表达式。`seq` 可以是 string 、迭代器范围、C 风格字符串。`m` 是一个 `smatch` / `ssub_match` 对象，用来保存匹配结果的相关细节。`m` 和 `seq` 必须具有兼容的类型。`mft` 是可选的 `regex_constants::match_flag_type` 值，影响匹配过程。

## 17.3.1 使用正则表达式库

查找违反拼写规则“只有在 c 之后的 i 可以在 e 后面，其他情况 i 只能在 e 之前”的单词：

```cpp
// 违反拼写规则的字符串应该是非 c 字母后接 ei 的
string pattern("[^c]ei"); // [^c] 匹配任意不是 c 的字符

// 使 pattern 能够匹配整个单词
pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*"; // [[:alpha:]] 表示任意字母，* 表示零个或多个，如果替换为 + 则表示一个或多个

// 初始化一个 regex 对象
regex r(pattern);

// 用于保存搜索结果的对象
smatch results;

// 测试文本
string test_str = "receipt freind theif receive";

// 用 r 在 test_str 中查找与 pattern 匹配的子串
if (regex_search(test_str, results, r)) // 如果有匹配的子串
    cout << results.str() << endl;      // 打印匹配的单词
```

regex / wregex 对象的操作：

* `regex r(re);` ：re 表示一个正则表达式，可以是 string 、字符串迭代器范围、C 风格字符串、字符指针加计数器、花括号包围的字符列表
* `regex r(re, f);` ：f 指出对象如何处理的标志，默认为 ECMAScript ，其他取值如下：
  * `icase` ：在匹配过程中忽略大小写
  * `nosubs` ：不保存匹配的子表达式
  * `optimize` ：执行速度优先于构造速度
  * `ECMAScript` ：使用 ECMA-262 指定的语法
  * `basic` ：使用 POSIX 基本的正则表达式语法
  * `extended` ：使用 POSIX 扩展的正则表达式语法
  * `awk` ：使用 POSIX 版本的 awk 语言的语法
  * `grep` ：使用 POSIX 版本的 grep 的语法
  * `egrep` ：使用 POSIX 版本的 egrep 的语法
  * 使用 `regex::` 或 `regex_constants::syntax_option_type::` 访问
* `r1 = re` ：将 r1 中的正则表达式替换为 re ，re 可以是另一个 regex 对象、string 、C 风格字符串、花括号包围的字符列表
* `r1.assign(re, f)` ：效果与 `=` 相同，f 取值同上
* `r.mark_count()` ：返回 r 中子表达式的数目
* `r.flags()` ：返回 r 的标志集

```cpp
// 匹配：一个或多个字母或数字，后接一个句点，再接三个文件扩展名之一，且忽略大小写
regex r("[[:alnum:]]+\\.(cpp|cxx|cc)$", regex::icase);
```

注意：`.` 在正则表达式中有特殊含义：匹配任意字符，需要使用反斜线转义；而反斜线在 C++ 中也有特殊含义：表示转义符号，需要再使用反斜线转义；所以表示字符的句点实际为 `\\.` 。

*一个正则表达式的语法是否正确是在运行时解析的。*

捕获正则表达式的语法错误异常：

```cpp
try
{
    regex r("[[:alnum:]+\\.(cpp|cxx|cc)$", regex::icase);
    //                ^ 丢失一个右括号
}
catch (regex_error e)
{
    cout << e.what() << "\ncode: " << e.code() << endl;
}
```

正则表达式的错误类型：

* `error_collate` ：无效的元素校对请求
* `error_ctype` ：无效的字符类
* `error_escape` ：无效的转义字符或无效的尾置转移
* `error_backref` ：无效的向后引用
* `error_brack` ：不匹配的方括号
* `error_paren` ：不匹配的圆括号
* `error_brace` ：不匹配的花括号
* `error_badbrace` ：{} 中无效的范围
* `error_range` ：无效的字符范围（如：[z-a]）
* `error_space` ：内存不足，无法处理此正则表达式
* `error_badrepeat` ：重复字符（* ? + {）之前没有有效的正则表达式
* `error_complexity` ：要求的匹配过于复杂
* `error_stack` ：栈空间不足，无法处理匹配

*正则表达式 regex 对象的创建十分耗时，应该在循环外创建，而不是在每次迭代都创建一个 regex 对象。*

`regex` 对象保存 char 的正则表达式；`wregex` 对象保存 wchar_t 的正则表达式。

`smatch` 保存 string 类型的查询结果；`cmatch` 保存字符数组序列；`wsmatch` 保存 wstring 序列；`wcmatch` 保存宽字符数组序列。

输入序列类型要与正则表达式库的类型匹配：

|输入序列类型|匹配的正则表达式库|
|:-:|:-:|
|string|regex, smatch, ssub_match, sregex_iterator|
|const char *|regex, cmatch, csub_match, cregex_iterator|
|wstring|wregex, wsmatch, wssub_match, wsregex_iterator|
|const wchat_t *|wregex, wcmatch, wcsub_match, wcregex_iterator|

## 17.3.2 匹配与 Regex 迭代器类型

前文中使用 `regex_search` 只能获得第一个匹配的字符串。现在可以使用 `sregex_iterator` 来获得所有匹配。

sregex_iterator 操作：

* `sregex_iterator it(b, e, r);` ：定义一个 sregex_iterator 对象 it ，遍历迭代器范围 b 和 e 表示的 string 。该对象调用 sregex_search(b, e, r) 将 it 指向输入序列中第一个匹配的位置
* `sregex_iterator end;` ：不带任何初始化参数的对象 end 代表 sregex_iterator 的尾后迭代器
* `*it` / `it->` ：根据最后一个调用 regex_search 的结果，返回一个 smatch 对象的引用或一个指向 smatch 对象的指针
* `++it` / `it++` ：从输入序列当前匹配位置开始调用 regex_search ，前置版本返回递增后迭代器，后置版本返回旧值（即：递增迭代器时，调用 regex_search 查找下一个匹配）
* `it1 == it2` / `it1 != it2` ：如果两个 sregex_iterator 都是尾后迭代器，则它们两个相等；两个非尾后迭代器是从相同的输入序列和 regex 对象构造，则它们相等
* 同样适用于 `cregex_iterator` 、`wsregex_iterator` 、`wcregex_iterator`

示例：

```cpp
for (sregex_iterator iter(test_str.begin(), test_str.end(), r), iter_end; // iter 指向第一个匹配，iter_end 是尾后迭代器
     iter != iter_end; ++iter)
{
    // 打印匹配单词的上文
    auto pos = iter->prefix().length(); // 获得前缀（上文）的大小
    pos = (pos > 40) ? pos - 40 : 0;   // 只输出前缀的后 40 个字符
    cout << iter->prefix().str().substr(pos) << "\n";
    
    cout << "\t\t>>> ";
    cout << iter->str(); // 每次迭代打印一个匹配的单词（iter 指向 smatch 对象）
    cout << " <<<\n";

    // 打印匹配单词的下文
    cout << iter->suffix().str().substr(0, 40) << endl; // 只输出后缀的前 40 个字符
}
```

smatch 操作：

* `m.ready()` ：如果已经通过 regex_search 或 regex_match 设置了 m ，则返回 true ，否则返回 false ；`对 m.ready()` 等于 false 的 m 进行操作是未定义的
* `m.size()` ：如果匹配失败，则返回 0 ；否则返回最近一次匹配的正则表达式中子表达式的数目
* `m.empty()` ：当 `m.size()` 返回 0 时为 true ，否则为 false
* `m.prefix()` ：返回一个 ssub_match 对象，表示当前匹配的上文
* `m.suffix()` ：返回一个 ssub_match 对象，表示当前匹配的下文
* `m.format(...)` ：见 [17.3.4](#1734-使用-regex_replace)
* 下列操作中，n 的值默认为 0 ，表示整个匹配，n 的值必须小于 `m.size()` ：
  * `m.length(n)` ：第 n 个匹配的子表达式的大小
  * `m.position(n)` ：第 n 个子表达式距序列开始的距离
  * `m.str(n)` ：第 n 个子表达式匹配的 string
  * `m[n]` ：对应第 n 个子表达式的 ssub_match 对象
* `m.begin()` / `m.end()` / `m.cbegin()` / `m.cend()` ：表示 m 中 sub_match 元素范围的迭代器
* 同样适用于 `cmatch - csub_match` 、`wsmatch - wssub_match` 、`wcmatch - wcsub_match`

## 17.3.3 使用子表达式

正则表达式使用括号表示子表达式。

```cpp
regex r("([[:alnum:]]+)\\.(cpp|cxx|cc)$", regex::icase);
// 子表达式 1 ：([[:alnum:]]+)
// 子表达式 2 ：(cpp|cxx|cc)

if (regex_search("foo.cpp", results, r))
{
    cout << results.str(1) << endl; // 打印子表达式 1 的内容 foo
    cout << results.str(2) << endl; // 打印子表达式 2 的内容 cpp
    cout << results.str(0) << endl; // 打印整个匹配序列的内容 foo.cpp
}
```

ECMAScript 语法：

* `\{d}` 匹配单个数字
* `\{d}{n}` 匹配 n 个数字
* `[字符集合]` 匹配字符集合中的任意一个（ `.` 在括号内没有特殊含义）
* `?` 前面的组件表示可选的，有或没有都会匹配

子表达式对象（`ssub_match` 、`csub_match` 、`wssub_match` 、`wcsub_match`）操作：

* `matched` ：public bool 数据成员，指出 sub_match 是否得到匹配
* `first` / `second` ：public 迭代器数据成员，指向匹配序列首元素和尾后位置；如果未匹配则两者相等
* `length()` ：匹配序列的大小，如果未匹配则返回 0
* `str()` ：返回匹配序列的 string ，如果未匹配则返回空 string
* `s = ssub` ：将 ssub_match 对象 ssub 转化为 string 对象 s ，等价于 `s = ssub.str()` ，不是 explicit 的

## 17.3.4 使用 regex_replace

正则表达式替换操作：

* `m.format(...)` ：使用格式字符串 `fmt` 生成格式化输出，匹配在 m 中，可选的 match_flag_type 标志在 `mft` 中。`mft` 的默认值为 format_default 。
  * `m.format(dest, fmt, mft)` 写入输入迭代器 dest 指向的目的位置并接受 `fmt` 参数，可以是一个 string ，也可以是表示字符数组中范围的一对指针
  * `m.format(fmt, mft)` 返回一个 string ，保存输出，并接受 `fmt` 参数，可以是一个 string ，也可以是一个指向空字符结尾的字符数组的指针
* `regex_replace(...)` ：遍历 `seq` ，用 regex_search 查找与 regex 对象 `r` 匹配的子串。使用格式字符串 `fmt` 和可选的 match_flag_type 标志来生成输出。`fmt` 既可以是一个 string 也可以是一个指向空字符结尾的字符数组的指针，且 `mft` 的默认值为 match_default 。
  * `regex_replace(dest, seq, r, fmt, mft)` 将输出写入到输入迭代器 dest 指定的位置，并接受一对迭代器 seq 表示范围
  * `regex_replace(seq, r, fmt, mft)` 返回一个 string ，保存输出，且 `seq` 既可以是一个 string ，也可以是一个指向空字符结尾的字符数组的指针

使用 `$` 后跟子表达式的索引号来使用一个特定的表达式：

```cpp
string phone_pattern = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
string fmt = "$2.$5.$7"; // 使用第 2 、5 、7 个子表达式构成新的格式

regex r(phone_pattern);
string number = "(908) 555-1800";
cout << regex_replace(number, r, fmt) << endl; // 输出 "908.555.1800"

string n_num = "name (908) 555-1800";
cout << regex_replace(n_num, r, fmt) << endl; // 输出 "name 908.555.1800" 序列中不匹配的部分默认保持原样

string new_fmt = "$2.$5.$7 "; // 新增一个空格
cout << regex_replace(n_num, r, new_fmt, format_no_copy) << endl; // 输出 "908.555.1800 " 后面跟一个空格，不拷贝不匹配的部分
```

匹配标志（使用 `regex_constants::match_flag_type::` 访问）：

* `match_default` ：等价于 format_default
* `match_not_bol` ：不将首字符作为行首处理
* `match_not_eol` ：不将尾字符作为行尾处理
* `match_not_bow` ：不将首字符作为单词首处理
* `match_not_eow` ：不将尾字符作为单词尾处理
* `match_any` ：如果存在多于一个匹配，则可返回任意一个匹配
* `match_not_null` ：不匹配任何空序列
* `match_continuous` ：匹配必须从输入的首字符开始
* `match_prev_avail` ：输入序列包含第一个匹配之前的内容
* `format_default` ：用 ECMAScript 规则替换字符串
* `format_sed` ：用 POSIX sed 规则替换字符串
* `format_no_copy` ：不输出输入序列中未匹配的部分
* `format_first_only` ：只替换子表达式的第一次出现

## 练习

* [练习 17.14](../src/quiz_17.14.cpp)
* [练习 17.15](../src/quiz_17.15.cpp)
* [练习 17.16](../src/quiz_17.16.cpp)
* [练习 17.17](../src/quiz_17.17.cpp)
* [练习 17.18](../src/quiz_17.18.cpp)
* [练习 17.19](../src/quiz_17.19.md)
* [练习 17.20](../src/quiz_17.20.cpp)
* [练习 17.21](../src/quiz_17.21.cpp)
* [练习 17.22](../src/quiz_17.22.cpp)
* [练习 17.23](../src/quiz_17.23.cpp)
* [练习 17.24](../src/quiz_17.24.cpp)
* [练习 17.25](../src/quiz_17.25.cpp)
* [练习 17.26](../src/quiz_17.26.cpp)
* [练习 17.27](../src/quiz_17.27.cpp)
