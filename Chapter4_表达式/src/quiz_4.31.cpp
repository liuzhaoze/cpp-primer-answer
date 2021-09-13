/**
 * 本节的程序使用了前置版本的递增运算符和递减运算符，
 * 解释为什么要用前置版本而不用后置版本。
 * 要想使用后置版本的递增递减运算符需要做哪些改动？
 * 使用后置版本重写本节的程序。
 */

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> ivec(10);
    vector<int>::size_type cnt = ivec.size();

    // 前置版本
    for (vector<int>::size_type ix = 0; ix != ivec.size(); ++ix, --cnt) {
        ivec[ix] = cnt;
    }

    // 后置版本
    for (vector<int>::size_type ix = 0; ix != ivec.size(); ix++, cnt--) {
        ivec[ix] = cnt;
    }

    for (auto i : ivec) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
/**
 * 前置版本运行效率比后置版本高
 * 但是实际运行结果没有区别
 */
