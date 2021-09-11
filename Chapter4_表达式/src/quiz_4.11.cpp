/**
 * 书写一条表达式用于测试 4 个值
 * a 、 b 、 c 、 d 的关系，
 * 确保 a 大于 b 、 b 大于 c 、 c 大于 d 。
 */

#include <iostream>

int main()
{
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;

    if (a > b && b > c && c > d) {
        std::cout << "a, b, c, d meet the requirement." << std::endl;
    }
    else {
        std::cout << "a, b, c, d don't meet the requirement." << std::endl;
    }

    return 0;
}
