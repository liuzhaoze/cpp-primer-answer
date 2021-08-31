/**
 * 编译并运行本节的程序，给它输入全都相等的值。
 * 再次运行程序，输入没有重复的值。
 */

#include <iostream>

int main()
{
    int currVal = 0, value = 0;

    // 读取第一个数，确保有数据可以处理
    if (std::cin >> currVal) {
        int cnt = 1;  // 当前值计数
        while (std::cin >> value) {
            // 处理下一个数
            if (value == currVal)
                ++cnt;
            else {
                std::cout << currVal << " occurs "
                          << cnt << " times " << std::endl;
                currVal = value;  // 记住新出现的值
                cnt = 1;  // 重置计数器
            }
        }

        // 输出最后一个数出现的个数
        std::cout << currVal << " occurs "
                  << cnt << " times " << std::endl;
    }

    return 0;
}
