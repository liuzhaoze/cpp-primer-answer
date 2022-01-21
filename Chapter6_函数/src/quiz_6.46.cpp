/**
 * 能把 isShorter 函数定义成 constexpr 函数吗？
 * 如果能，将他改写成 constexpr 函数；
 * 如果不能，说明原因。
 */

#include <string>

using std::string;

constexpr bool isShort(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

/**
 * 不能！
 * 因为 size() 函数的返回值不是 constexpr 函数；
 * 而且 s1.size() < s2.size() 也不是常量表达式。
 */
