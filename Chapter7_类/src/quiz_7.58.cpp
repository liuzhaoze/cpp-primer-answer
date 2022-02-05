/**
 * 下面的静态数据成员的声明和定义有错误吗？请解释原因。
 */

#include <vector>

class Example
{
public:
    // static double rate = 6.5; // 只有常量静态数据成员允许在类内进行初始化
    static constexpr double rate = 6.5; // 改

    static const int vecSize = 20;

    // static std::vector<double> vec(vecSize); // vecSize 存在于类外，无法在类内调用
    static std::vector<double> vec; // 改（在类内声明，在类外定义）
};

// double Example::rate;
constexpr double Example::rate; // 改

// std::vector<double> Example::vec;
std::vector<double> Example::vec(Example::vecSize); // 改
