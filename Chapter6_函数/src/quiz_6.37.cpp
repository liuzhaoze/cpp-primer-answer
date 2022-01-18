/**
 * 为上一题的函数再写三个声明，一个使用类型别名，另一个使用尾置返回类型，最后一个使用 decltype 关键字。
 * 你觉得哪种形式最好？为什么？
 */

#include <string>

using std::string;
using strAType = string[10];

string strArr[10];

string (&func(int i))[10];

strAType &func1(int i);
auto func2(int i) -> string (&)[10];
decltype(strArr) &func3(int i);

// 使用类型别名的方法更加直观，更好。
