/**
 * 编写函数，接受一个 istream& 参数，返回值类型也是 istream& 。
 * 此函数需从给定的流中读取数据，直至遇到文件结束标识时停止。
 * 它将读取的数据打印在标准输出上。
 * 完成这些操作后，在返回流之前对流进行复位，使其处于有效状态。
 */
#ifndef QUIZ_8_1_HPP
#define QUIZ_8_1_HPP

#include <iostream>
#include <string>

std::istream &func_quiz_8_1(std::istream &istrm);

std::istream &func_quiz_8_1(std::istream &istrm)
{
    std::string str;

    while (istrm >> str)
    {
        std::cout << str << std::endl;
    }

    istrm.clear(); // 对流进行复位

    return istrm;
}

#endif
