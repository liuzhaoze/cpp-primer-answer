/**
 * 对本节给出的 seek 程序，编写你自己的版本。
 */

#include <cstddef>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

int main()
{
    std::fstream io_file("../data/copyOut", std::fstream::in | std::fstream::out |
                                                std::fstream::ate); // 文件可读可写，并且标记初始在文件末尾 8.2.2
    if (!io_file)
    {
        std::cerr << "Unable to open file!" << std::endl;
        return EXIT_FAILURE; // main 函数的可选返回值 6.3.2
    }

    // 程序读取到原始文件末尾时停止
    auto end_mark = io_file.tellg();     // 记录原始文件末尾
    io_file.seekg(0, std::fstream::beg); // 标记移动至文件开头
    std::size_t count = 0;               // 字节数累加器
    std::string line;                    // 存储每行输入

    // 文件流有效 && 标记尚未处于原始文件末尾 && 读取下一行成功
    while (io_file && io_file.tellg() != end_mark && std::getline(io_file, line))
    {
        count += line.size() + 1;    // 累加累加本行长度以及一个换行符
        auto mark = io_file.tellg(); // 记录当前标记位置，以便在文件末尾输出字符后返回继续读取
        io_file.seekp(0, std::fstream::end); // 标记移动到文件末尾
        io_file << count;                    // 输出累计字节数

        if (mark != end_mark) // 如果尚未完胜读取，则输出一个分隔符
        {
            io_file << " ";
        }

        io_file.seekg(mark); // 返回读取中断时的位置
    }

    // 在文件末尾输出换行符
    io_file.seekp(0, std::fstream::end);
    io_file << std::endl;

    return 0;
}
