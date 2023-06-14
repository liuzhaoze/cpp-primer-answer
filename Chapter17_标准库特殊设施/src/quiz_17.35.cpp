/**
 * 修改练习 17.34 中的程序，打印 2 的平方根，但这次打印十六进制数字的大写形式。
 */

#include <cmath>
#include <iostream>

int main()
{
    std::cout << "default format: " << 100 * std::sqrt(2.0) << std::endl;
    std::cout << "scientific: " << std::scientific << 100 * std::sqrt(2.0) << std::endl;
    std::cout << "fixed decimal: " << std::fixed << 100 * std::sqrt(2.0) << std::endl;
    std::cout << "hexadecimal: " << std::hexfloat << std::uppercase << 100 * std::sqrt(2.0) << std::endl;
    std::cout << "use default: " << std::defaultfloat << 100 * std::sqrt(2.0) << std::endl;

    return 0;
}
