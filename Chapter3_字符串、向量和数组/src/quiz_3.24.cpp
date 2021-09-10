/**
 * 请使用迭代器重做 3.3.3 节的最后一个练习。
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

    for (auto i = ivec.cbegin(); i != ivec.cend() - 1; ++i) {
        cout << *i + *(i + 1) << " ";
    }
    cout << endl;

    auto top = ivec.cbegin();
    auto bottom = ivec.cend() - 1;
    decltype(ivec.size()) i = 0;
    while (i < ivec.size() / 2) {
        cout << *(top + i) + *(bottom - i) << " ";
        ++i;
    }
    cout << endl;

    return 0;
}
