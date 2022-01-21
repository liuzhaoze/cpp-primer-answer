/**
 * 将 isShorter 函数改写成内联函数。
 */

#include <string>

using std::string;

inline bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}
