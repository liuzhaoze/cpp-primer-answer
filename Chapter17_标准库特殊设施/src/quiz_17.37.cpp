/**
 * 用未格式化版本的 getline 逐行读取一个文件。
 * 测试你的程序，给它一个文件，既包含空行又包含长度超过你传递给 getline 的字符数组大小的行。
 */

#include <fstream>
#include <iostream>

int main()
{
    std::ifstream in_file("../data/test");
    char sink[50];

    while (in_file.getline(sink, 50)) // 读取大于 50 个字符的行会停止读取
    {
        std::cout << sink << std::endl;
    }

    return 0;
}
