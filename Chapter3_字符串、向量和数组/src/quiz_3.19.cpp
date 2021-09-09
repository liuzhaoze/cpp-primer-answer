/**
 * 如果想定义一个含有 10 个元素的 vector 对象，
 * 所有元素的值都是 42 ，请列举出三种不同的实现方法。
 * 哪种方法更好呢？为什么？
 */

#include <vector>

using std::vector;

int main()
{
    vector<int> v1(10, 42);  // 这种最好
    vector<int> v2{42, 42, 42, 42, 42, 42, 42, 42, 42, 42};
    vector<int> v3;

    for (int i = 0; i < 10; ++i) {
        v3.push_back(42);
    }

    return 0;
}
