/**
 * 编写一段程序，比较两个数组是否相等。
 * 再写一段程序，比较两个 vector 对象是否相等。
 */

#include <iostream>
#include <vector>
#include <iterator>

using std::begin;
using std::cin;
using std::cout;
using std::end;
using std::endl;
using std::vector;

int main()
{
    int ia1[5], ia2[5], num;
    vector<int> iv1, iv2;

    // 输入数据
    unsigned cnt = 0;
    while (cin >> num) {
        if (cnt < 5) {
            ia1[cnt++] = num;
            iv1.push_back(num);
        }
        else if (cnt < 10) {
            ia2[cnt++ - 5] = num;
            iv2.push_back(num);
        }
        else {
            std::cerr << "10 numbers are required." << endl;
            return -1;
        }
    }

    // 判断数组是否相等
    bool equal = true;
    for (size_t i = 0; i != 5; ++i) {
        if (ia1[i] != ia2[i]) {
            equal = false;
            break;
        }
    }
    if (equal) {
        cout << "ia1 is equal to ia2." << endl;
    }
    else {
        cout << "ia1 is not equal to ia2." << endl;
    }

    // 判断 vector 对象是否相等
    if (iv1 == iv2) {
        cout << "iv1 is equal to iv2." << endl;
    }
    else {
        cout << "iv1 is not equal to iv2." << endl;
    }

    return 0;
}
