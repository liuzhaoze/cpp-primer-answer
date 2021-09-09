/**
 * 下列的 vector 对象各包含多少个元素？
 * 这些元素的值分别是多少？
 */

#include <string>
#include <vector>

using std::string;
using std::vector;

int main()
{
    vector<int> v1;  // 包含 0 个元素
    vector<int> v2(10);  // 包含 10 个 0
    vector<int> v3(10, 42);  // 包含 10 个 42
    vector<int> v4{10};  // 包含 1 个 10
    vector<int> v5{10, 42};  // 包含 1 个 10 和 1 个 42
    vector<string> v6{10};  // 包含 10 个空字符串
    vector<string> v7{10, "hi"};  // 包含 10 个 "hi" 字符串

    return 0;
}
