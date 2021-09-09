/**
 * 下列 vector 对象的定义有不正确的吗？
 * 如果有，请指出来。
 * 对于正确的，描述其执行结果；
 * 对于不正确的，说明其错误的原因。
 */

#include <string>
#include <vector>

using std::string;
using std::vector;

int main()
{
    vector<vector<int>> ivec;  // ivec 向量的元素是 vector 对象

    vector<string> svec = ivec;  // 非法， string 与 vector<int> 类型不一致

    vector<string> svec(10, "null");  // svec 向量中含有 10 个 "null" 字符串

    return 0;
}
