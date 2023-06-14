/**
 * 修改上一题中的程序，打印不同的浮点数，使它们排成一列。
 */

#include <cmath>
#include <iomanip>
#include <iostream>

int main()
{
    std::cout << std::setw(20) << "default format: " << std::setw(22) << 100 * std::sqrt(2.0) << std::endl;
    std::cout << std::setw(20) << "scientific: " << std::scientific << std::setw(22) << 100 * std::sqrt(2.0)
              << std::endl;
    std::cout << std::setw(20) << "fixed decimal: " << std::fixed << std::setw(22) << 100 * std::sqrt(2.0) << std::endl;
    std::cout << std::setw(20) << "hexadecimal: " << std::hexfloat << std::uppercase << std::setw(22)
              << 100 * std::sqrt(2.0) << std::endl;
    std::cout << std::setw(20) << "use default: " << std::defaultfloat << std::setw(22) << 100 * std::sqrt(2.0)
              << std::endl;

    return 0;
}
