/**
 * 调用上述 vector 对象中的每个元素并输出其结果。
 */

#include <vector>
#include <iostream>

using std::cout;
using std::endl;
using std::vector;

int int_sum(int a, int b)
{
    cout << __func__ << " called." << endl;
    return a + b;
}

int int_minus(int a, int b)
{
    cout << __func__ << " called." << endl;
    return a - b;
}

int int_multiply(int a, int b)
{
    cout << __func__ << " called." << endl;
    return a * b;
}

int int_divide(int a, int b)
{
    cout << __func__ << " called." << endl;
    return (b == 0) ? 0 : a / b;
}


int main(int argc, char **argv)
{
    int a = 10, b = 5;
    vector<decltype(int_sum) *> vec = {int_sum, int_minus, int_multiply, int_divide};

    for (auto pf : vec)
    {
        cout << pf(a, b) << endl;
    }

    return 0;
}
