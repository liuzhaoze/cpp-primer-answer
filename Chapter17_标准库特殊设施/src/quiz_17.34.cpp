/**
 * 编写一个程序，展示如何使用操纵符。
 */

#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

int main()
{
    std::cout << "default bool values: " << true << " " << false << std::endl;
    std::cout << "alpha bool values: " << std::boolalpha << true << " " << false << std::noboolalpha << std::endl;

    std::cout << std::showbase;
    std::cout << "default: " << 20 << " " << 1024 << std::endl;
    std::cout << "octal: " << std::oct << 20 << " " << 1024 << std::endl;
    std::cout << "hex: " << std::hex << 20 << " " << 1024 << std::endl;
    std::cout << "decimal: " << std::dec << 20 << " " << 1024 << std::endl;
    std::cout << std::noshowbase;

    std::cout << std::uppercase << std::showbase << std::hex << "print in hexadecimal: " << 20 << " " << 1023
              << std::nouppercase << std::noshowbase << std::dec << std::endl;

    // 返回当前精度值
    std::cout << "Precision: " << std::cout.precision() << ", Value: " << std::sqrt(2.0) << std::endl;
    // 将精度设置为 12 位有效数字
    std::cout.precision(12);
    std::cout << "Precision: " << std::cout.precision() << ", Value: " << std::sqrt(2.0) << std::endl;
    // 另一种设置精度的方法
    std::cout << std::setprecision(3);
    std::cout << "Precision: " << std::cout.precision() << ", Value: " << std::sqrt(2.0) << std::endl;

    std::cout.precision(6); // 恢复默认
    std::cout << "default format: " << 100 * std::sqrt(2.0) << std::endl;
    std::cout << "scientific: " << std::scientific << 100 * std::sqrt(2.0) << std::endl;
    std::cout << "fixed decimal: " << std::fixed << 100 * std::sqrt(2.0) << std::endl;
    std::cout << "hexadecimal: " << std::hexfloat << 100 * std::sqrt(2.0) << std::endl;
    std::cout << "use default: " << std::defaultfloat << 100 * std::sqrt(2.0) << std::endl;

    // 打印小数点
    std::cout << 10.0 << std::endl;
    std::cout << std::showpoint << 10.0 << std::noshowpoint << std::endl;

    int i = -16;
    double d = 3.14159;
    // 输出至少占 12 个字符
    std::cout << "i: " << std::setw(12) << i << "next col" << std::endl;
    std::cout << "d: " << std::setw(12) << d << "next col" << std::endl;
    // 左对齐
    std::cout << std::left;
    std::cout << "i: " << std::setw(12) << i << "next col" << std::endl;
    std::cout << "d: " << std::setw(12) << d << "next col" << std::endl;
    std::cout << std::right; // 恢复默认
    // 符号和数值分别对齐
    std::cout << std::internal;
    std::cout << "i: " << std::setw(12) << i << "next col" << std::endl;
    std::cout << "d: " << std::setw(12) << d << "next col" << std::endl;
    // 用 # 代替空格填充
    std::cout << std::setfill('#');
    std::cout << "i: " << std::setw(12) << i << "next col" << std::endl;
    std::cout << "d: " << std::setw(12) << d << "next col" << std::endl;
    std::cout << std::setfill(' '); // 恢复默认

    std::ifstream in_file("../data/no-skipws");
    char ch;

    while (in_file >> ch)
    {
        std::cout << ch;
    }
    std::cout << std::endl;

    // 重置文件输入流
    in_file.clear();
    in_file.seekg(0);

    in_file >> std::noskipws;
    while (in_file >> ch)
    {
        std::cout << ch;
    }
    in_file >> std::skipws; // 恢复默认
    std::cout << std::endl;

    return 0;
}
