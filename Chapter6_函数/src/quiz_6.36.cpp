/**
 * 编写一个函数的声明，使其返回数组的引用并且该数组包含 10 个 string 对象。
 * 不要使用尾置返回类型、 decltype 或者类型别名。
 */

#include <string>

using std::string;

string (&func(int i))[10];
