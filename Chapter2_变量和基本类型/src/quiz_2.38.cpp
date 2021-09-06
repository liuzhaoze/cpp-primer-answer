/**
 * 说明由 decltype 指定类型和由 auto 指定类型有何区别。
 * 请举出一个例子， decltype 指定的类型与 auto 指定的类型一样；
 * 再举一个例子， decltype 指定的类型与 auto 指定的类型不一样。
 */

#include <iostream>

int main()
{
    int i = 4;
    const int ci = 5;

    // 相同
    auto i1 = i;     // int
    decltype(i) i2;  // int

    // 不同
    auto ci1 = ci;          // int
    decltype(ci) ci2 = ci;  // const int

    return 0;
}
