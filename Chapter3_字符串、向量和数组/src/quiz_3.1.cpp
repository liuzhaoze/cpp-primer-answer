/**
 * 使用恰当的 using 声明重做 1.4.1 节和 2.6.2 节的练习。
 */

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    // 1.9
    int sum = 0, val = 50;

    while (val <= 100) {
        sum += val;
        ++val;
    }

    cout << "Sum of 50 to 100 inclusive is "
         << sum << endl;
    
    // 1.10
    val = 10;

    while (val >= 0) {
        cout << val-- << endl;
    }

    // 1.11
    int v1, v2;

    cin >> v1 >> v2;

    if (v1 > v2) {
        int temp;
        temp = v1;
        v1 = v2;
        v2 = temp;
    }

    while (v1 <= v2) {
        cout << v1++ << endl;
    }

    // 2.6.2 略

    return 0;
}
