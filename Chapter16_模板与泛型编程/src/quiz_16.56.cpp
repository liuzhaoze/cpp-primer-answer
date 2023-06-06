/**
 * 编写并测试可变参数版本的 errorMsg 。
 */

#include <iostream>
#include <ostream>
#include <sstream>
#include <string>

/* quiz_16.48.cpp */

// [1] 可以接受任何类型，打印无法处理的类型
template <typename T> std::string debug_rep(const T &t)
{
    std::ostringstream ret;
    ret << t;
    return ret.str();
}

// [2] 处理指针类型（不能处理 char* ，因为 << char* 会输出字符数组的内容，而非指针的地址）
template <typename T> std::string debug_rep(T *p)
{
    std::ostringstream ret;
    ret << "pointer: " << p; // 打印指针储存的地址

    if (p)
    {
        ret << " " << debug_rep(*p); // 打印 p 指向的对象
    }
    else
    {
        ret << " null pointer"; // 指出指针为空
    }

    return ret.str();
}

// [3] 非模板的函数，只处理 string 的引用
std::string debug_rep(const std::string &s)
{
    return '"' + s + '"';
}

/* quiz_16.53.cpp */

template <typename T> std::ostream &print(std::ostream &os, const T &t)
{
    return os << t;
}

template <typename T, typename... Args> std::ostream &print(std::ostream &os, const T &t, const Args &...rest)
{
    os << t << ", ";
    return print(os, rest...);
}

/* quiz_16.56.cpp */

template <typename... Args> std::ostream &errorMsg(std::ostream &os, const Args &...rest)
{
    return print(os, debug_rep(rest)...);
}

int main()
{
    errorMsg(std::cout, 1, 2, 3, 4, 9.0f, "sss", "alan") << std::endl;
    return 0;
}
