/**
 * 读入一组整数并把它们存入一个 vector 对象，
 * 将每对相邻整数的和输出出来。
 * 改写你的程序，这次要求先输出第 1 个和最后 1 个元素的和，
 * 接着输出第 2 个和倒数第 2 个元素的和，以此类推。
 */

#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    vector<int> ivec;
    int num;

    while (cin >> num) {
        ivec.push_back(num);
        cout << num << " ";
    }
    cout << endl;

    for (decltype(ivec.size()) i = 0; i < ivec.size() - 1; ++i) {
        cout << ivec[i] + ivec[i + 1] << " ";
    }
    cout << endl;

    for (decltype(ivec.size()) i = 0; i < ivec.size() / 2; ++i) {
        cout << ivec[i] + ivec[ivec.size() - 1 - i] << " ";
    }
    cout << endl;

    return 0;
}
