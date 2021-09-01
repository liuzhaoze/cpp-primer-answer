/**
 * 请利用转义序列编写一段程序，要求先输出 2M ，然后转到新一行。
 * 修改程序使其先输出 2 ，然后输出制表符，再输出 M ，最后转到新一行。
 */

#include <iostream>

int main()
{
    std::cout << "\062\115\n\062\t\115\n"
              << std::endl;

    return 0;
}
