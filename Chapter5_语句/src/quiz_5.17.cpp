/**
 * 假设有两个包含整数的 vector 对象，编写一段程序，检验其中一个 vector 对象是否是另一个的前缀。
 * 为了实现这一目标，对于两个不等长的 vector 对象，只需挑出长度较短的那个，把他的所有元素和另一个 vector 对象比较即可。
 * 例如，如果两个 vector 对象的元素分别是0、1、1、2和0、1、1、2、3、5、8，则程序的返回结果应该为真。
 */

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> v1 = {0, 1, 1, 2};
    vector<int> v2 = {0, 1, 1, 2, 3, 5, 8};
    vector<int> v_short, v_long;

    if (v1.size() < v2.size())
    {
        v_short = v1;
        v_long = v2;
    }
    else
    {
        v_short = v2;
        v_long = v1;
    }

    decltype(v_short.size()) ix;
    for (ix = 0; ix != v_short.size() && v_short[ix] == v_long[ix]; ++ix)
        ;
    
    if (ix < v_short.size())
        cout << "false" << endl;
    else
        cout << "true" << endl;

    return 0;
}
