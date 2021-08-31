/**
 * 使用 for 循环重做练习 1.9 1.10 1.11 。
 */

#include <iostream>

int main()
{
    // quiz_1.9
    int sum = 0;

    for (int val = 50; val <= 100; ++val)
        sum += val;
    
    std::cout << "Sum of 50 to 100 inclusive is "
              << sum << std::endl;

    // quiz_1.10
    for (int val = 10; val >= 0; val--)
        std::cout << val << std::endl;

    // quiz_1.11
    int v1, v2;

    std::cin >> v1 >> v2;

    if (v1 > v2) {
        int temp;
        temp = v1;
        v1 = v2;
        v2 = temp;
    }

    for (; v1 <= v2; v1++)
        std::cout << v1 << std::endl;

    return 0;
}
