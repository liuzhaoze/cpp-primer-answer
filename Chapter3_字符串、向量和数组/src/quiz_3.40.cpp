/**
 * 编写一段程序，定义两个字符数组并用字符串字面值初始化它们；
 * 接着再定义一个字符数组存放前两个数组连接后的结果。
 * 使用 strcpy 和 strcat 把前两个数组的内容拷贝到第三个数组中。
 */

#include <cstdio>
#include <cstring>

using std::printf;
using std::strcat;
using std::strcpy;

int main()
{
    char ca1[] = "Hello";
    char ca2[] = "World";
    char ca3[30];

    strcpy(ca3, ca1);
    strcat(ca3, " ");
    strcat(ca3, ca2);
    strcat(ca3, "!");

    printf("%s\n", ca3);

    return 0;
}
