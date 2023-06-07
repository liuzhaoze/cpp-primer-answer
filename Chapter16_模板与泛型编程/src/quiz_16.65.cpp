/**
 * 在 16.3 节中我们定义了两个重载的 debug_rep 版本，一个接受 const char * 参数，另一个接受 char * 参数。
 * 将这两个函数重写为特例化版本。
 */

#include <iostream>
#include <sstream>
#include <string>

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

// [4] 特例化 [2] 的 char * 版本
template <> std::string debug_rep(char *p)
{
    return debug_rep(std::string(p));
}

// [5] 特例化 [2] 的 const char * 版本
template <> std::string debug_rep(const char *p)
{
    return debug_rep(std::string(p));
}

int main()
{
    std::string s("hi");
    std::cout << debug_rep(s) << std::endl;
    /**
     * 定义 [3] 之前：
     * 只有 [1] 版本是可行的。
     * 因为 [2] 版本需要传入指针，无法进行实例化。
     *
     * 定义 [3] 之后：
     * [1] debug_rep(const string &) T 推断为 string
     * [3] debug_rep(const string &) 非模板函数
     * 优先选择非模板版本，所以选择版本 [3]
     */

    std::cout << debug_rep(&s) << std::endl;
    /**
     * [1] [2] 两个版本都可以实例化。
     * [1] debug_rep(const string * &) T 推断为 string *
     * [2] debug_rep(string *) T 推断为 string
     * 因为 [1] 需要将普通指针转换为 const 指针，[2] 的参数是精确匹配
     * 所以选择版本 [2]
     */

    const std::string *sp = &s;
    std::cout << debug_rep(sp) << std::endl;
    /**
     * [1] [2] 两个版本都可以实例化。
     * [1] debug_rep(const string * &) T 推断为 string *
     * [2] debug_rep(const string *) T 推断为 const string
     * 因为 [1] (const T &) 适用于任何类型，[2] (T *) 只适用于指针类型
     * [2] 比 [1] 更特例化，所以选择版本 [2]
     */

    std::cout << debug_rep("hi world!") << std::endl;
    char c[5] = {'a', 'b', 'c', 'd', '\0'};
    std::cout << debug_rep(c) << std::endl;
    /**
     * 在 quiz_16.48 中，[2] 中函数把 p 当作指针处理，如果希望将字符指针当作 string 处理，可以定义两个非模板的重载版本：
     * string debug_rep(char *p) { return debug_rep(string(p)); }
     * string debug_rep(const char *p) { return debug_rep(string(p)); }
     * 在函数体中将字符指针转换为 string 然后调用其他重载版本
     *
     * 现将上述两个非模板重载函数改写为特例化的函数模板，现在 debug_rep 可以正常处理字符指针
     */

    return 0;
}
