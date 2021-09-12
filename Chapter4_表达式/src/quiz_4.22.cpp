/**
 * 本节的示例程序将成绩划分成 high pass 、 pass 和 fail 三种，
 * 扩展该程序使其进一步将 60 分到 75 分之间的成绩设定为 low pass 。
 * 要求程序包含两个版本：
 * 一个版本只使用条件运算符；
 * 另一个版本使用 1 个或多个 if 语句。
 * 哪个版本的程序更容易理解呢？为什么？
 */

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    unsigned grade;

    cout << "grade\t"
         << "ver.1\t\t"
         << "ver.2" << endl;

    while (cin >> grade) {
        cout << grade << "\t";

        // 版本 1
        cout << ((grade > 90) ? "high pass\t"
                              : ((grade > 75) ? "pass\t\t"
                                              : ((grade > 60) ? "low pass\t" : "fail\t\t")));

        // 版本 2
        if (grade > 90) {
            cout << "high pass" << endl;
        }
        else if (grade > 75) {
            cout << "pass" << endl;
        }
        else if (grade > 60) {
            cout << "low pass" << endl;
        }
        else {
            cout << "fail" << endl;
        }
    }

    // 那必然是第二个版本更容易理解
    return 0;
}
